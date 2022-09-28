#ifndef _COMMON_H
#define _COMMON_H

#include <ctype.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <inttypes.h>
#include <endian.h>
#include <linux/limits.h>


int signedcalc(int64_t operand1, uint8_t operator, int64_t operand2, int64_t * write_result);

int unsignedcalc(uint64_t operand1, uint8_t operator, uint64_t operand2, int64_t * write_result);

int operand_decider(char *operand2);

int signage_decider(uint16_t operator);

#endif