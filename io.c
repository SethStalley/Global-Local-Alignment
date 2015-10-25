#include "io.h"

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
