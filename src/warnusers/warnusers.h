#ifndef WARNUSERS_H
#define WARNUSERS_H

#include <libcircle.h>

void add_objects(CIRCLE_handle *handle);
void process_objects(CIRCLE_handle *handle);
int warnusers_create_redis_attr_cmd(char *buf, struct stat *st, char *filename, char *filekey);
int warnusers_redis_run_zadd(char *filekey, long val, char *zset, char *filename);
void warnusers_redis_run_cmd(char *cmd, char *filename);
int warnusers_redis_keygen(char *buf, char *filename);
void print_usage(char **argv);
void warnusers_redis_run_sadd(int uid);
#endif /* WARNUSERS_H */
