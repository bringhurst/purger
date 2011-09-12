#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#include <libcircle.h>
#include <log.h>

char *TOP_DIR;

void
add_objects(CIRCLE_handle *handle)
{
    handle->enqueue(TOP_DIR);
}

void
process_objects(CIRCLE_handle *handle)
{
    DIR *current_dir;
    char temp[CIRCLE_MAX_STRING_LEN];
    char stat_temp[CIRCLE_MAX_STRING_LEN];
    struct dirent *current_ent; 
    struct stat st;

    /* Pop an item off the queue */ 
    handle->dequeue(temp);
    LOG(LOG_DBG, "Popped [%s]\n", temp);

    /* Try and stat it, checking to see if it is a link */
    if(lstat(temp,&st) != EXIT_SUCCESS)
    {
            LOG(LOG_ERR, "Error: Couldn't stat \"%s\"\n", temp);
            //MPI_Abort(MPI_COMM_WORLD,-1);
    }
    /* Check to see if it is a directory.  If so, put its children in the queue */
    else if(S_ISDIR(st.st_mode) && !(S_ISLNK(st.st_mode)))
    {
        current_dir = opendir(temp);
        if(!current_dir) {
            LOG(LOG_ERR, "Unable to open dir");
        }
        else
        {
            /* Read in each directory entry */
            while((current_ent = readdir(current_dir)) != NULL)
            {
            /* We don't care about . or .. */
            if((strncmp(current_ent->d_name,".",2)) && (strncmp(current_ent->d_name,"..",3)))
                {
                    strcpy(stat_temp,temp);
                    strcat(stat_temp,"/");
                    strcat(stat_temp,current_ent->d_name);

                    LOG(LOG_DBG, "Pushing [%s] <- [%s]\n", stat_temp, temp);
                    handle->enqueue(&stat_temp[0]);
                }
            }
        }
        closedir(current_dir);
    }
    //else if(S_ISREG(st.st_mode) && (st.st_size % 4096 == 0))
    else if(S_ISREG(st.st_mode)) {
        LOG(LOG_DBG, "%s\n",temp);
    }
}

int
main (int argc, char **argv)
{
    int index;
    int c;
     
    opterr = 0;
    while((c = getopt(argc, argv, "d:")) != -1)
    {
        switch(c)
        {
            case 'd':
                TOP_DIR = optarg;
                break;
            case '?':
                if (optopt == 'd')
                    fprintf(stderr, "Option -%c requires an argument.\n", optopt);
                else if (isprint (optopt))
                    fprintf(stderr, "Unknown option `-%c'.\n", optopt);
                else
                    fprintf(stderr,
                        "Unknown option character `\\x%x'.\n",
                        optopt);

                exit(EXIT_FAILURE);
            default:
                abort();
        }
    }

    if(argc < 2) {
         fprintf(stderr, "Usage: %s -d <starting directory>\n", argv[0]);
         exit(EXIT_FAILURE);
    }
    for (index = optind; index < argc; index++)
        printf ("Non-option argument %s\n", argv[index]);

    CIRCLE_init(argc, argv);
    CIRCLE_cb_create(&add_objects);
    CIRCLE_cb_process(&process_objects);
    CIRCLE_begin();
    CIRCLE_finalize();

    exit(EXIT_SUCCESS);
}

/* EOF */
