#include "alignment.h"
#include "aux.h"
#include <string.h>

//edit these from main to change behavior
int GAP_PENALTY =  -1;
int MATCH = 1;
int MISMATCH = -1;

//score equality of two chars
int score(char a, char b){
  return a == b ? MATCH : MISMATCH;
}

/*
  Globally Aligns two secuences using Needleman Wunsch's algorithm
  @Input:
    String1
    String2
  Both should be of equal length
*/
int globalAlignment(char *secA, char *secB){
  int lenA = strlen(secA)+1;
  int lenB = strlen(secB)+1;

  //declare our score matrix
  int scoreMatrix[lenA][lenB];

  //fill first columns with 0's
  for(int i=0;i<lenA;i++)
    scoreMatrix[i][0] = -i;
  //fill first row with 0's
  for(int i=0;i<lenB;i++)
    scoreMatrix[0][i] = -i;


  //score the secuences
  for(int i = 1; i < lenA; i++)
    for(int j = 1; j < lenB; j++)
    {
      //score diagonal
      int scoreDiag =
      scoreMatrix[i-1][j-1]+ score(secA[i-1],secB[j-1]);


      //score left one
      int leftScore = scoreMatrix[i][j-1] + GAP_PENALTY;
      //score up one
      int upScore = scoreMatrix[i-1][j] + GAP_PENALTY;

      int scores[3] = {scoreDiag, leftScore, upScore};

      //pick the best
      scoreMatrix[i][j] = max(scores, 3);
    }
    //uncomment to see score matrix
  //printMatrix(lenA,lenB,scoreMatrix);

  //compute alignment
  char AlignmentA[2*lenA];
  char AlignmentB[2*lenB];


  int i = lenA-1;
  int j = lenB-1;

  int a = 0;

  while (i > 0 || j > 0)
  {
    if(i > 0 && j > 0 &&
    scoreMatrix[i][j] == scoreMatrix[i-1][j-1]+score(secA[i-1], secB[j-1]))
    {
      AlignmentA[a] = secA[i-- -1];
      AlignmentB[a] = secB[j-- -1];
    }
    else if(i > 0 && scoreMatrix[i][j] == scoreMatrix[i-1][j] + GAP_PENALTY)
    {
      AlignmentA[a] = secA[i-- -1];
      AlignmentB[a] = '-';
    }
    else
    {
      AlignmentA[a] = '-';
      AlignmentB[a] = secB[j-- -1];
    }
    a++;
  }
  AlignmentA[a] = AlignmentB[a] = 0;

  strReverse(AlignmentA);
  strReverse(AlignmentB);
  printf("%s\n", AlignmentA);
  printf("%s\n", AlignmentB);

  //all is good
  return 1;
}

/*
  Locally Aligns two secuences using Smith-Waterman's algorithm
  @Input:
    String1
    String2
  Both should be of equal length
*/


//
//
// // *** AUXILIAR METHODS FOR LOCAL ALIGNMENT IMPLEMENTATION***
//
// static int s(int i, int j, char *secA, char *secB)
// {
//     return ((secA[i] == secB[j]) ? 1 : -1);
// }
//
//
// // H functions returns the maximun similarity score from a suffix of a[1...i] and a suffix of b[1...j]
// static int H(int i, int j, int **matrix, char *secA, char *secB)
// {
//     int n[3];
//     n[0]=n[1]=n[2]=0;
//
//     n[0] = matrix[i-1][j-1] + s(i,j,secA,secB);
//     n[1] = matrix[i-1][j] + GAP_PENALTY;
//     n[2] = matrix[i][j-1] + GAP_PENALTY;
//
//     return max(n,3);
// }
//
//
//
// // ************************************
//
// int localAlignment(char *secA, char *secB)
// {
//     int lenA = 2+strlen(secA);
//     int lenB = 2+strlen(secB);
//     int i, j;
//
//     int matrix[lenA][lenB];
//
//     // setmatrix(matrix,lenA,lenB,0);
//     //
//     // for(i=0; i<lenA; i++){
//     //     for(j=0; j <lenB;j++){
//     //         matrix[i][j] = H(i,j,matrix,secA,secB);
//     //     }
//     // }
//
//
// }
