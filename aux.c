#include "aux.h"

//fills all the cells in a matrix with the same value
// void setmatrix(int **matrix, int lenA, int lenB, int val)
// {
//     for(i=0; i<lenA; i++){
//         for(j=0; j <lenB;j++){
//             matrix[i][j] = val;
//         }
// }

//returns the greatest of list of numbers
int max(int numbers[], int len){
  int max = numbers[0];
  for(int i = 1; i< len; i++)
    if(numbers[i] > max)
      max = numbers[i];
      
  return max;
}

void printMatrix(int *matrix, int lenA, int lenB){
  puts("Matrix is:");
  for(int i =0; i< lenA; i++){
    for(int j = 0; j<lenB;j++)
      printf("%d\t", *((matrix+i*lenB)+j));
    puts("");
  }
}

//reverses a string
void strReverse(char *str){
  /* skip null */
  if (str == 0)
  {
  	return;
  }

  /* skip empty string */
  if (*str == 0)
  {
  	return;
  }

  /* get range */
  char *start = str;
  char *end = start + strlen(str) - 1; /* -1 for \0 */
  char temp;

  /* reverse */
  while (end > start)
  {
  	/* swap */
  	temp = *start;
  	*start = *end;
  	*end = temp;

  	/* move */
  	++start;
  	--end;
  }
}
