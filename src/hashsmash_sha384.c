#include <openssl/sha.h>		/* SHA384_DIGEST_LENGTH, SHA384() */

#ifndef HASH_DIGEST_LENGTH
# define HASH_DIGEST_LENGTH SHA384_DIGEST_LENGTH
#endif

#ifndef HASH
# define HASH SHA384
#endif


#include "main.c"
