#include "ldap.h"

int get_email( const char *uid, const char* ldap_host, const char *base, char *email ) {
  LDAP *ld;
  int  result;
  int  auth_method = LDAP_AUTH_SIMPLE;
  int desired_version = LDAP_VERSION3;

  BerElement* ber;
  LDAPMessage* msg;
  LDAPMessage* entry;

  char filter[64]="(uid=";
  char* errstring;
  char* dn = NULL;
  char* attr;
  char** vals;
  int i;
  int ret=1;

  if ((ld = ldap_init(ldap_host, LDAP_PORT)) == NULL ) {
    perror( "ldap_init failed" );
    exit( EXIT_FAILURE );
  }

  /* set the LDAP version to be 3 */
  if (ldap_set_option(ld, LDAP_OPT_PROTOCOL_VERSION, &desired_version) != LDAP_OPT_SUCCESS)
    {
      ldap_perror(ld, "ldap_set_option");
      exit(EXIT_FAILURE);
    }

  strncat(filter, uid, 58);
  strncat(filter, ")", 1);

  if (ldap_search_s(ld, base, LDAP_SCOPE_SUBTREE, filter, NULL, 0, &msg) != LDAP_SUCCESS) {
    ldap_perror( ld, "ldap_search_s" );
    exit(EXIT_FAILURE);
  }

  /* printf("The number of entries returned was %d\n\n", ldap_count_entries(ld, msg)); */

  /* Iterate through the returned entries */
  for(entry = ldap_first_entry(ld, msg); entry != NULL; entry = ldap_next_entry(ld, entry)) {

    /* if((dn = ldap_get_dn(ld, entry)) != NULL) {
        printf("Returned dn: %s\n", dn);
        ldap_memfree(dn);
       }
    */

    for( attr = ldap_first_attribute(ld, entry, &ber); 
	 attr != NULL; 
	 attr = ldap_next_attribute(ld, entry, ber)) {
      if ((vals = ldap_get_values(ld, entry, attr)) != NULL) {
	for(i = 0; vals[i] != NULL; i++) {
	  if (strncmp (attr, "mail", 4) == 0) {
	    /* printf("%s: %s\n", attr, vals[i]); */
	    strncpy(email, vals[i], 128);
	    ret=0;
	    break;
	  }
	}

	ldap_value_free(vals);
      }

      ldap_memfree(attr);
    }

    if (ber != NULL) {
      ber_free(ber,0);
    }
    /* printf("\n"); */
  }

  /* clean up */
  ldap_msgfree(msg);
  result = ldap_unbind_s(ld);

  if (result != 0) {
    fprintf(stderr, "ldap_unbind_s: %s\n", ldap_err2string(result));
    exit( EXIT_FAILURE );
  }

  return ret;
}