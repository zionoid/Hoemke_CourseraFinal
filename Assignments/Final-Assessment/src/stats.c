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
 * @file stats.c
 * @date 02-15-2022
 * @author Landon Hoemke
 */
#include <stdio.h>
#include "../include/common/stats.h"
#include "../include/common/platform.h"

#define SIZE (40)

void print_statistics (unsigned char minimum, unsigned char maximum, float mean, unsigned char median){
  printf("The min is %d \n", minimum);
  printf("The max is %d \n", maximum);
  printf("The mean is %f \n", mean);
  printf("The median is %d \n", median);
}


void print_array (unsigned char *array, unsigned int counter){
  #ifdef VERBOSE
    for (int i=0; i<counter; i++){
      PRINTF("%d \t ", *(array + i));
    }
    PRINTF("\n");
  #endif
}


unsigned char find_median (unsigned char *array, unsigned int counter){
  unsigned char median = 0;
  median = *(array + (counter / 2) -1);
  return median;
}

float find_mean (unsigned char *array, unsigned int counter){
  unsigned int accumulator = 0; 
  float mean = 0;
  for (int i=0; i<counter; i++){
    accumulator = accumulator + array[i] /* *(array + i) */;
  }
  printf("acc = %d \n", accumulator);
  mean = accumulator / ((float) counter); 
  return mean;
}

unsigned char find_maximum (unsigned char *array, unsigned int counter){
  unsigned char maximum = *array; 
  for (int i=1; i<counter; i++){ 
    if (*(array + i) > maximum){
      maximum = *(array + i);
    }
    else {} 
  }
  return maximum;
}

unsigned char find_minimum (unsigned char *array, unsigned int counter){
  unsigned char minimum = *array; 
  for (int i=1; i<counter; i++){ 
    if (*(array + i) < minimum){
      minimum = *(array + i);
    }
    else {} 
  }
  return minimum;
}


void sort_array (unsigned char *array, unsigned int counter){
  char flag = 0; 
  unsigned char temp;
  do {
	  
    flag =0; 
	
    for (int index=0; index<counter; index++){
		
      if (array[index] > array[index +1] || array[index] == array[index +1]) {
        continue;
      }
      else if (array[index] < array[index +1]) {
        temp = array[index];
        array[index] = array[index+1];
        array[index+1] = temp;

        flag = 1;
      }
    }
  }
  while (flag ==1); 
}
