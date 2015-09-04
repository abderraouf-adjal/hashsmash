/* 
 * Copyright (c) 2014, Abderraouf Adjal
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
 * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
 * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/* HashSmash - Simple hash brute-force software using CPU */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  /* isdigit(), isxdigit() */
#include <string.h>
#include <sysexits.h>
#include <limits.h>


#ifndef MAX_EXPECTED_BYTES_NUM
# define MAX_EXPECTED_BYTES_NUM 25
#endif


int str_isdigit(const char *str, size_t len);
int str_isxdigit(const char *str, size_t len);
void hex2bin(unsigned char *digest, const char *hex, size_t len);


int main(int argc, char **argv)
{
	unsigned char min_char, max_char;
	size_t expected_bytes_num;
	
	unsigned char last_str[MAX_EXPECTED_BYTES_NUM + 1],
				cmp_str[MAX_EXPECTED_BYTES_NUM + 1],
				cmp_str_digest[HASH_DIGEST_LENGTH],
				hash_digest[HASH_DIGEST_LENGTH];
	
	
	/* make the arrays NULL */
	memset(last_str, 0, sizeof(last_str));
	memset(cmp_str, 0, sizeof(cmp_str));
	memset(cmp_str_digest, 0, sizeof(cmp_str_digest));
	memset(hash_digest, 0, sizeof(hash_digest));
	
	
	if (argc < 5 || argc > 7) {
		fprintf(stderr, "%s: ERROR: Invalid CLI arguments.\n", argv[0]);
		fprintf(stderr, "Usage:  %s expected_bytes_number min_char max_char hash [start_bytes_hex] [end_bytes_hex]\n", argv[0]);
		exit(EX_USAGE);
	}
	
	if (!str_isdigit(argv[1], strlen(argv[1])) || atoll(argv[1]) <= 0 || atoll(argv[1]) > MAX_EXPECTED_BYTES_NUM) {
		fprintf(stderr, "%s: ERROR: Invalid or long (>%u) [expected bytes number]: %s\n", argv[0], MAX_EXPECTED_BYTES_NUM, (!strlen(argv[1]) ? "NULL" : argv[1]));
		exit(EX_DATAERR);
	} else {
		expected_bytes_num = atoll(argv[1]);
	}
	
	if (!str_isdigit(argv[2], strlen(argv[2])) || atoll(argv[2]) > UCHAR_MAX) {
		fprintf(stderr, "%s: ERROR: Invalid or long (>%u) [min ascii char]: %s\n", argv[0], UCHAR_MAX, (!strlen(argv[2]) ? "NULL" : argv[2]));
		exit(EX_DATAERR);
	} else {
		min_char = atoll(argv[2]);
	}
	
	if (!str_isdigit(argv[3], strlen(argv[3])) || atoll(argv[3]) > UCHAR_MAX) {
		fprintf(stderr, "%s: ERROR: Invalid or long (>%u) [max ascii char]: %s\n", argv[0], UCHAR_MAX, (!strlen(argv[3]) ? "NULL" : argv[3]));
		exit(EX_DATAERR);
	} else {
		max_char = atoll(argv[3]);
	}
	
	if (min_char > max_char) { /* eg: min_char=126 && max_char=32 */
		fprintf(stderr, "%s: ERROR: [min ascii char] > [max ascii char]\n", argv[0]);
		exit(EX_DATAERR);
	}
	
	if (strlen(argv[4]) != HASH_DIGEST_LENGTH * 2 || !str_isxdigit(argv[4], HASH_DIGEST_LENGTH * 2)) {
		fprintf(stderr, "%s: ERROR: Invalid hash: %s\n", argv[0], (!strlen(argv[4]) ? "NULL" : argv[4]));
		exit(EX_DATAERR);
	} else {
		hex2bin(hash_digest, argv[4], HASH_DIGEST_LENGTH);
	}
	
	
	/* Make: cmp_str, last_str */
	if (argc == 5) {
		memset(cmp_str, min_char, expected_bytes_num);
		memset(last_str, max_char, expected_bytes_num);
	}
	else if (argc == 6 || argc == 7) {
		if (strlen(argv[5]) != expected_bytes_num * 2 || !str_isxdigit(argv[5], expected_bytes_num * 2)) {
			fprintf(stderr, "%s: ERROR: Invalid start bytes hex: %s\n", argv[0], (!strlen(argv[5]) ? "NULL" : argv[5]));
			exit(EX_DATAERR);
		} else {
			hex2bin(cmp_str, argv[5], expected_bytes_num);
			
			for (size_t i = 0; i < expected_bytes_num; i++) {
				if (cmp_str[i] < min_char || cmp_str[i] > max_char) {
					fprintf(stderr, "%s: ERROR: Invalid start bytes hex: %s\n", argv[0], (!strlen(argv[5]) ? "NULL" : argv[5]));
					exit(EX_DATAERR);
				}
			}
		}
		
		if (argc == 6) {
			memset(last_str, max_char, expected_bytes_num);
		} else if (argc == 7) {
			if (strlen(argv[6]) != expected_bytes_num * 2 || !str_isxdigit(argv[6], expected_bytes_num * 2)) {
				fprintf(stderr, "%s: ERROR: Invalid end bytes hex: %s\n", argv[0], (!strlen(argv[6]) ? "NULL" : argv[6]));
				exit(EX_DATAERR);
			} else {
				hex2bin(last_str, argv[6], expected_bytes_num);
				
				for (size_t i = 0; i < expected_bytes_num; i++) {
					if (last_str[i] < min_char || last_str[i] > max_char) {
						fprintf(stderr, "%s: ERROR: Invalid end bytes hex: %s\n", argv[0], (!strlen(argv[6]) ? "NULL" : argv[6]));
						exit(EX_DATAERR);
					}
				}
			}
		}
		
		for (size_t i = 0; i < expected_bytes_num; i++) { /* e.g.: cmp_str=7E7E ; last_str=2020 */
			if (cmp_str[i] > last_str[i]) {
				fprintf(stderr, "%s: ERROR: Invalid start or end bytes hex.\n", argv[0]);
				exit(EX_DATAERR);
			}
		}
	}
	
	
	while (1)
	{
		HASH((unsigned char*)&cmp_str, expected_bytes_num, (unsigned char*)&cmp_str_digest);
		
		if (!memcmp(cmp_str_digest, hash_digest, HASH_DIGEST_LENGTH)) { /* Check the matching */
			printf("String: '%s'\nIn Hex: ", cmp_str);
			for (size_t i = 0; i < expected_bytes_num; i++) {
				printf("%02x", cmp_str[i]);
			}
			printf("\n");
			return EX_OK;
		}
		
		if (!memcmp(cmp_str, last_str, expected_bytes_num)) { /* The loop limit */
			fprintf(stderr, "No match.\n");
			return 1;
		}
		
		/* Make the bytes array - Big Endian */
		for (size_t i = 0; i < expected_bytes_num; i++) { /* fast to find: za ; slow to find: az; {aa, ba, ca, ...} */
			if (cmp_str[i] < max_char) {
				cmp_str[i]++;
				break;
			} else {
				cmp_str[i] = min_char;
			}
		}
		
		/* Make the bytes array - Little Endian */
		//for (size_t i = expected_bytes_num - 1; i >= 0; i--) { /* fast to find: az ; slow to find: za; {aa, ab, ac, ...} */
			//if (cmp_str[i] < max_char) {
				//cmp_str[i]++;
				//break;
			//} else {
				//cmp_str[i] = min_char;
			//}
		//}
		
		/* Make the bytes array - Little Endian */
		//for (size_t i = 1; i <= expected_bytes_num; i++) { /* fast to find: az ; slow to find: za; {aa, ab, ac, ...} */
			//if (cmp_str[expected_bytes_num - i] < max_char) {
				//cmp_str[expected_bytes_num - i]++;
				//break;
			//} else {
				//cmp_str[expected_bytes_num - i] = min_char;
			//}
		//}
		
	}
}


int str_isxdigit(const char *str, size_t len)
{
	if (len == 0) {
		return 0;
	}
	
	for(size_t i = 0; i < len; i++) {
		if (!isxdigit(str[i])) {
			return 0;
		}
	}
	
	return 1;
}


int str_isdigit(const char *str, size_t len)
{
	if (len == 0) {
		return 0;
	}
	
	for(size_t i = 0; i < len; i++) {
		if (!isdigit(str[i])) {
			return 0;
		}
	}
	
	return 1;
}


unsigned char chars_to_byte(char a, char b)
{
	char tmp[] = {a, b, '\0'};
	return strtoul(tmp, NULL, 16);
}

void hex2bin(unsigned char *digest, const char *hex, size_t len)
{
	/* Convert hash in hex to bytes */
	for (size_t i = 0; i / 2 < len; i += 2) {
		digest[i / 2] = chars_to_byte(hex[i], hex[i + 1]);
	}
}
