#include <openssl/sha.h>		/* SHA512_DIGEST_LENGTH, SHA512() */

#ifndef HASH_DIGEST_LENGTH
# define HASH_DIGEST_LENGTH SHA512_DIGEST_LENGTH
#endif

#ifndef HASH
# define HASH SHA512
#endif


#include "main.c"
