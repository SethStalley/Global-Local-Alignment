#include "alignment.h"

/*
  Run Flags
    #Does global alignment of two input files
    -global filename1 filename2
*/
int main(int argc, char const *argv[]) {
  char tempSecA[] = "GCATGCA";
  char tempSecB[] = "GATTAC";

  globalAlignment(tempSecA,tempSecB);

  return 0;
}
