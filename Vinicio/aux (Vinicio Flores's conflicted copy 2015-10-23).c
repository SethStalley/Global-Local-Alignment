#include "aux.h"

//fills all the cells in a matrix with the same value
void setmatrix(mcell_t **matrix, int lenA, int lenB, int val)
{
    for(i=0; i<lenA; i++){
        for(j=0; j <lenB;j++){
            matrix[i][j].val = val;
        }
}

//returns the greatest of list of numbers
// For Smith-Waterman only.
int Max(int numbers[], int len, mcell_t **matrix,int i, int j){
  int max = numbers[0];
  for(int i = 1; i< len; i++)
    if(numbers[i] > max)
      max = numbers[i];
  if(max = numbers[0]){
      matrix[i][j].origin_direction_arrow_i = i-1;
      matrix[i][j].origin_direction_arrow_j = j-1;
  }

  else if( max = numbers[1] ){
      matrix[i][j].origin_direction_arrow_i = i-1;
      matrix[i][j].origin_direction_arrow_j = j;
  }

  else {
      matrix[i][j].origin_direction_arrow_i = i;
      matrix[i][j].origin_direction_arrow_j = j-1;
  }


  return max;
}

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

void printSmithMatrix(mcell_t *matrix, int lenA, int lenB){
  puts("Matrix is:");
  for(int i =0; i< lenA; i++){
    for(int j = 0; j<lenB;j++)
      printf("%d\t", *((matrix+i*lenB)+j).val);
    puts("");
  }
}
