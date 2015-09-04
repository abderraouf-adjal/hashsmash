#include <openssl/md5.h>		/* MD5_DIGEST_LENGTH, MD5() */

#ifndef HASH_DIGEST_LENGTH
# define HASH_DIGEST_LENGTH MD5_DIGEST_LENGTH
#endif

#ifndef HASH
# define HASH MD5
#endif


#include "main.c"
