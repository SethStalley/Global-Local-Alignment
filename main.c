#include "alignment.h"

/*
  Run Flags
    #Does global alignment of two input files
    -global filename1 filename2
*/
int main(int argc, char const *argv[]) {
  char tempSecA[] = "GCATGCU";
  char tempSecB[] = "GATTACA";     // xD like the movie!

  globalAlignment(tempSecA,tempSecB);

  return 0;
}
