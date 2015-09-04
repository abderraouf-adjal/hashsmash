#include <openssl/sha.h>		/* SHA_DIGEST_LENGTH, SHA() */

#ifndef HASH_DIGEST_LENGTH
# define HASH_DIGEST_LENGTH SHA_DIGEST_LENGTH
#endif

#ifndef HASH
# define HASH SHA
#endif


#include "main.c"
