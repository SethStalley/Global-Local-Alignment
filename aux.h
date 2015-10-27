#ifndef __AUX_H
#define __AUX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <time.h>

void save_timing(long long *nsec,
      struct timespec st,
      struct timespec et
);

int max(int numbers[], int len);
void printMatrix(int lenA, int lenB,int matrix[][lenB]);
void strReverse(char* str);

#endif
