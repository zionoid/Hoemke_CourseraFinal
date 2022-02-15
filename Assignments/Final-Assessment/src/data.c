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
/**
 * @file data.c
 * @date 02-15-2022
 * @author Landon Hoemke
 */

#include <stdint.h>
#include <stddef.h>
#include "../include/common/memory.h"
#include "../include/common/data.h"
#include "../include/common/platform.h"

uint8 my_itoa(int32 data, uint8 * ptr, uint32 base)
{
  uint8 isNegative= 0;
  uint8 digitCounter= 0;
  uint8 remainder= 0;  

  if (data == 0)
  {
    *(ptr) = '0';
    *(ptr + 1) = '\0';
    return 2;
  }
  
  if (data < 0)
  {
    isNegative = 1;
    data = data*-1;
  }  
  while (data != 0)
  {
    remainder = data % base;
    *(ptr + digitCounter)= ( remainder > 9 ) ? ( remainder - 10 ) + 'a' : remainder + '0';
    digitCounter++;
    data= data / base;
  }  
  
  if (isNegative)
  {
    *(ptr + digitCounter) = '-';
    digitCounter++;
  }  
  digitCounter++;
  *(ptr + digitCounter) = '\0';

  my_reverse(ptr, (digitCounter - 1));
  
  return digitCounter;
}

int32 my_atoi(uint8 * ptr, uint8 digits, uint32 base)
{
  int32 number = 0;
  uint8 isNegative = 0;

  if(*ptr == '-')
  {
    isNegative = 1;
    ptr++;
    digits--;
  }

  digits--;

  for(int i = 0; i < digits; i++)
  {
    number = number * base + *ptr - '0';
    ptr++;
  }

  if(isNegative)
  {
    number = -number;
  }

  return number;
}

