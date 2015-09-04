#include <openssl/sha.h>		/* 224_DIGEST_LENGTH, SHA224() */

#ifndef HASH_DIGEST_LENGTH
# define HASH_DIGEST_LENGTH SHA224_DIGEST_LENGTH
#endif

#ifndef HASH
# define HASH SHA224
#endif


#include "main.c"
