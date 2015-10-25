#include "alignment.h"

#define PRM_GLOBAL "-global"

/*
    @Input
        - Path to txt file or file name if same dir
    @Output (**Is Dinamic**)
        - String containing contents of a .txt
*/
char * strFromFile(const char *path){
    FILE *f;
    int size;
    char *buffer;

    f = fopen(path,"r");
    //if file exists
    if(f==NULL) return NULL;

    fseek(f, 0, SEEK_END);
    size = ftell(f); //number of bytes in file
    rewind (f);

    // allocate memory to contain the whole file:
    buffer = (char*) malloc (sizeof(char)*size);
    if (buffer == NULL){
     puts("Memory error");
     return NULL;
    }
    // copy the file into the buffer:
    fread (buffer,1,size,f);

    fclose(f);
    return buffer;
}

/*
  Run Flags
    #Does global alignment of two input files
    -global filename1.txt filename2.txt
*/
int main(int argc, char const *argv[]) {

    //load two files
  if(argc == 4 && strcmp(argv[1], PRM_GLOBAL) == 0){
      char *secuenceA = strFromFile(argv[2]);
      char *secuenceB = strFromFile(argv[3]);
      if(secuenceA && secuenceB)
        globalAlignment(secuenceA,secuenceB);
      else
        puts("Error! those files don't exist");
  }else{
      char tempSecA[] = "GCATGCA";
      char tempSecB[] = "GATTAC";
      globalAlignment(tempSecA,tempSecB);
  }


  return 0;
}
