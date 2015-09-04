#include <openssl/ripemd.h>		/* RIPEMD160_DIGEST_LENGTH, RIPEMD160() */

#ifndef HASH_DIGEST_LENGTH
# define HASH_DIGEST_LENGTH RIPEMD160_DIGEST_LENGTH
#endif

#ifndef HASH
# define HASH RIPEMD160
#endif


#include "main.c"
