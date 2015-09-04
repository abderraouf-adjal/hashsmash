#include <openssl/sha.h>		/* SHA256_DIGEST_LENGTH, SHA256() */

#ifndef HASH_DIGEST_LENGTH
# define HASH_DIGEST_LENGTH SHA256_DIGEST_LENGTH
#endif

#ifndef HASH
# define HASH SHA256
#endif


#include "main.c"
