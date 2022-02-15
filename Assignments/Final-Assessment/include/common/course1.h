/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
#ifndef __COURSE1_H__
#define __COURSE1_H__

#include <stdint.h>

#define DATA_SET_SIZE_W (10)
#define MEM_SET_SIZE_B  (32)
#define MEM_SET_SIZE_W  (8)
#define MEM_ZERO_LENGTH (16)

#define TEST_MEMMOVE_LENGTH (16)
#define TEST_ERROR          (1)
#define TEST_NO_ERROR       (0)
#define TESTCOUNT           (8)

void course1(void);

int8_t test_data1();

int8_t test_data2();

int8_t test_memmove1();

int8_t test_memmove2();

int8_t test_memmove3();

int8_t test_memcopy();

int8_t test_memset();

int8_t test_reverse();

#endif /* __COURSE1_H__ */

