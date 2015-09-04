#include <openssl/md4.h>		/* MD4_DIGEST_LENGTH, MD4() */

#ifndef HASH_DIGEST_LENGTH
# define HASH_DIGEST_LENGTH MD4_DIGEST_LENGTH
#endif

#ifndef HASH
# define HASH MD4
#endif


#include "main.c"
