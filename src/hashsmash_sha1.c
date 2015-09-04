#include <openssl/sha.h>		/* SHA_DIGEST_LENGTH, SHA1() */

#ifndef HASH_DIGEST_LENGTH
# define HASH_DIGEST_LENGTH SHA_DIGEST_LENGTH
#endif

#ifndef HASH
# define HASH SHA1
#endif


#include "main.c"
