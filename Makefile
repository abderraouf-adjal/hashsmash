# Make file for POSIX compatible OSs

CC = gcc
CFLAGS = -std=c99 -O3 -funroll-loops
WARNINGS = -Wall -Wstrict-prototypes -Wdeclaration-after-statement -Wsign-compare -Winit-self
LIBS = -lcrypto

RM = rm -f
CP = cp -f
CHMOD = chmod
BFP = 755
NFP = 644

SRCD = src/
TGT = bin/

INSTALL_ROOT = /usr
BIN_DIR = $(INSTALL_ROOT)/bin/


# list of source files
hashsmash_MD4_SRC = hashsmash_md4.c
hashsmash_MD4_BIN = hashsmash_md4

hashsmash_MD5_SRC = hashsmash_md5.c
hashsmash_MD5_BIN = hashsmash_md5

hashsmash_SHA_SRC = hashsmash_sha.c
hashsmash_SHA_BIN = hashsmash_sha

hashsmash_SHA1_SRC = hashsmash_sha1.c
hashsmash_SHA1_BIN = hashsmash_sha1

hashsmash_SHA224_SRC = hashsmash_sha224.c
hashsmash_SHA224_BIN = hashsmash_sha224

hashsmash_SHA256_SRC = hashsmash_sha256.c
hashsmash_SHA256_BIN = hashsmash_sha256

hashsmash_SHA384_SRC = hashsmash_sha384.c
hashsmash_SHA384_BIN = hashsmash_sha384

hashsmash_SHA512_SRC = hashsmash_sha512.c
hashsmash_SHA512_BIN = hashsmash_sha512

hashsmash_RIPEMD160_SRC = hashsmash_ripemd160.c
hashsmash_RIPEMD160_BIN = hashsmash_ripemd160


all:
	$(CC) $(WARNINGS) $(CFLAGS) $(SRCD)$(hashsmash_MD4_SRC) -o $(TGT)$(hashsmash_MD4_BIN) $(LIBS)
	
	$(CC) $(WARNINGS) $(CFLAGS) $(SRCD)$(hashsmash_MD5_SRC) -o $(TGT)$(hashsmash_MD5_BIN) $(LIBS)
	
	$(CC) $(WARNINGS) $(CFLAGS) $(SRCD)$(hashsmash_SHA_SRC) -o $(TGT)$(hashsmash_SHA_BIN) $(LIBS)
	
	$(CC) $(WARNINGS) $(CFLAGS) $(SRCD)$(hashsmash_SHA1_SRC) -o $(TGT)$(hashsmash_SHA1_BIN) $(LIBS)
	
	$(CC) $(WARNINGS) $(CFLAGS) $(SRCD)$(hashsmash_SHA224_SRC) -o $(TGT)$(hashsmash_SHA224_BIN) $(LIBS)
	$(CC) $(WARNINGS) $(CFLAGS) $(SRCD)$(hashsmash_SHA256_SRC) -o $(TGT)$(hashsmash_SHA256_BIN) $(LIBS)
	$(CC) $(WARNINGS) $(CFLAGS) $(SRCD)$(hashsmash_SHA384_SRC) -o $(TGT)$(hashsmash_SHA384_BIN) $(LIBS)
	$(CC) $(WARNINGS) $(CFLAGS) $(SRCD)$(hashsmash_SHA512_SRC) -o $(TGT)$(hashsmash_SHA512_BIN) $(LIBS)
	
	$(CC) $(WARNINGS) $(CFLAGS) $(SRCD)$(hashsmash_RIPEMD160_SRC) -o $(TGT)$(hashsmash_RIPEMD160_BIN) $(LIBS)

install:
	$(CP) $(TGT) $(BIN_DIR)
	$(CP) $(TGT) $(BIN_DIR)
	$(CP) $(TGT) $(BIN_DIR)
	$(CP) $(TGT) $(BIN_DIR)
	$(CP) $(TGT) $(BIN_DIR)
	$(CP) $(TGT) $(BIN_DIR)
	$(CP) $(TGT) $(BIN_DIR)
	$(CP) $(TGT) $(BIN_DIR)
	$(CP) $(TGT) $(BIN_DIR)
	
	$(CHMOD) $(BFP) $(BIN_DIR)$(hashsmash_MD4_BIN)
	$(CHMOD) $(BFP) $(BIN_DIR)$(hashsmash_MD5_BIN)
	$(CHMOD) $(BFP) $(BIN_DIR)$(hashsmash_SHA_BIN)
	$(CHMOD) $(BFP) $(BIN_DIR)$(hashsmash_SHA1_BIN)
	$(CHMOD) $(BFP) $(BIN_DIR)$(hashsmash_SHA224_BIN)
	$(CHMOD) $(BFP) $(BIN_DIR)$(hashsmash_SHA256_BIN)
	$(CHMOD) $(BFP) $(BIN_DIR)$(hashsmash_SHA384_BIN)
	$(CHMOD) $(BFP) $(BIN_DIR)$(hashsmash_SHA512_BIN)
	$(CHMOD) $(BFP) $(BIN_DIR)$(hashsmash_RIPEMD160_BIN)

clean:
	$(RM) $(TGT)*

uninstall:
	$(RM) $(BIN_DIR)$(hashsmash_MD4_BIN)
	$(RM) $(BIN_DIR)$(hashsmash_MD5_BIN)
	$(RM) $(BIN_DIR)$(hashsmash_SHA_BIN)
	$(RM) $(BIN_DIR)$(hashsmash_SHA1_BIN)
	$(RM) $(BIN_DIR)$(hashsmash_SHA224_BIN)
	$(RM) $(BIN_DIR)$(hashsmash_SHA256_BIN)
	$(RM) $(BIN_DIR)$(hashsmash_SHA384_BIN)
	$(RM) $(BIN_DIR)$(hashsmash_SHA512_BIN)
	$(RM) $(BIN_DIR)$(hashsmash_RIPEMD160_BIN)
