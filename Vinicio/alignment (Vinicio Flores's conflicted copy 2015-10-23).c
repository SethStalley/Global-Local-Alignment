#include "alignment.h"
#include "aux.h"
#include <string.h>

#define GAP_PENALTY  -2
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
  int scoreMatrix[lenB][lenA];

  //fill first row with 0's
  for(int i=0;i<lenA;i++)
    scoreMatrix[0][i] = -i;
  //fill first columns with 0's
  for(int i=0;i<lenB;i++)
    scoreMatrix[i][0] = -i;

  //score the secuences
  for(int i = 1; i < lenA; i++)
    for(int j = 1; j < lenB; j++)
    {
      //score diagonal
      int scoreDiag = 0;
      if(secA[i-1] == secB[j-1])
        scoreDiag = scoreMatrix[i-1][j-1] + 1;
      else
        scoreDiag = scoreMatrix[i-1][j-1] -1;

      //score left one
      int leftScore = scoreMatrix[i][j-1] - 1;
      //score up one
      int upScore = scoreMatrix[i-1][j] - 1;

      int scores[3] = {scoreDiag, leftScore, upScore};

      //pick the best
      scoreMatrix[i][j] = max(scores, 3);
    }

  printMatrix((int *)scoreMatrix, lenA,lenB);

  //compute alignment
  char AlignmentA[lenA];
  char AlignmentB[lenB];

  
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




// *** AUXILIAR METHODS FOR LOCAL ALIGNMENT IMPLEMENTATION***

static int s(int i, int j, char *secA, char *secB)
{
    return ((secA[i] == secB[j]) ? 1 : -1);
}


// H functions returns the maximun similarity score from a suffix of a[1...i] and a suffix of b[1...j]
static int H(int i, int j, int **matrix, char *secA, char *secB)
{
    int n[3];
    n[0]=n[1]=n[2]=0;
    
    n[0] = matrix[i-1][j-1].val + s(i,j,secA,secB);
    n[1] = matrix[i-1][j].val + GAP_PENALTY;
    n[2] = matrix[i][j-1].val + GAP_PENALTY;
    
    return Max(n,3,matrix,i,j);
}






// ************************************

int localAlignment(char *secA, char *secB)
{
    int lenA = 2+strlen(secA);
    int lenB = 2+strlen(secB);
    int i, j;
 
    mcell_t matrix[lenA][lenB];
    setmatrix(matrix,lenA,lenB,0);
    
    for(i=0; i<lenA; i++){
        for(j=0; j <lenB;j++){
            matrix[i][j].val = H(i,j,matrix,secA,secB);
        }
    }
    
    
}