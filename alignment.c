#include "alignment.h"
#include "aux.h"
#include <string.h>



//score equality of two chars
int score(char a, char b, int match, int mismatch){
  return a == b ? match : mismatch;
}

/*
  Globally Aligns two secuences using Needleman Wunsch's algorithm
  @Input:
    String1
    String2
    type: 0 = local Waterman or 1 = global Needleman
  Both should be of equal length
*/
int alignment(char *secA, char *secB, int type,
int match,int mismatch,int gapPenalty){
  int lenA = strlen(secA)+1;
  int lenB = strlen(secB)+1;

  //declare our score matrix
  int scoreMatrix[lenA][lenB];

  //fill first columns with 0's
  for(int i=0;i<lenA;i++)
    scoreMatrix[i][0] = type ? -i : 0;
  //fill first row with 0's
  for(int i=0;i<lenB;i++)
    scoreMatrix[0][i] = type ? -i : 0;


  //score the secuences
  for(int i = 1; i < lenA; i++)
    for(int j = 1; j < lenB; j++)
    {
      //score diagonal
      int scoreDiag =
      scoreMatrix[i-1][j-1]+ score(secA[i-1],secB[j-1], match, mismatch);


      //score left one
      int leftScore = scoreMatrix[i][j-1] + gapPenalty;
      //score up one
      int upScore = scoreMatrix[i-1][j] + gapPenalty;

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
    scoreMatrix[i][j] == scoreMatrix[i-1][j-1]+score(secA[i-1], secB[j-1], match, mismatch))
    {
      AlignmentA[a] = secA[i-- -1];
      AlignmentB[a] = secB[j-- -1];
    }
    else if(i > 0 && scoreMatrix[i][j] == scoreMatrix[i-1][j] + gapPenalty)
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
