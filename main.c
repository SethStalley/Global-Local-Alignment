#include "alignment.h"
#include "io.h"

//argument parameters
#define PRM_GLOBAL "-global"
#define PRM_LOCAL "-local"

/*
  Run Flags
    #Does global alignment of two input files
    -global filename1.txt filename2.txt
*/
int main(int argc, char const *argv[]) {
    //load parameters from params.txt
    int params[3];
    loadParams(params);
    //set params from txt
    int match = params[0];
    int mismatch = params[1];
    int gapPenalty = params[2];

    //load two files
  if(argc == 4 && ((strcmp(argv[1], PRM_GLOBAL) == 0)  || (strcmp(argv[1], PRM_LOCAL) == 0))  ){
      char *secuenceA = strFromFile(argv[2]);
      char *secuenceB = strFromFile(argv[3]);
      int size = strlen(secuenceA);
      printf("%d\n",size);
      size = strlen(secuenceB);
      printf("%d\n", size);
      if(secuenceA && secuenceB){
        if  (strcmp(argv[1], PRM_GLOBAL) == 0)
            //global alignment
            alignment(secuenceA,secuenceB, 1,
            match, mismatch, gapPenalty);
        else if(strcmp(argv[1], PRM_LOCAL) == 0)
            //local alignment
            alignment(secuenceA,secuenceB, 0,
            match, mismatch, gapPenalty);
      }
      else
        puts("Error! those files don't exist");

      free(secuenceA);
      free(secuenceB);
  }else{
      puts("Blank or wrong param! Doing default");
      char tempSecA[] = "GCATGCA";
      char tempSecB[] = "GATTACA";
      alignment(tempSecA,tempSecB, 1,
      match, mismatch, gapPenalty);
  }
  return 0;
}
