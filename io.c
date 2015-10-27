#include "io.h"

/*
    @input
        - three element int array
        -params.txt must exist in Path
    @Output
        -list cantaing three basic paramenters in form
        [Match, Mismatch, Gap]
*/
void loadParams(int *params){
    char *file = strFromFile("params.txt");
    int size = strlen(file);

    char strParam[3];
    int paramNum = 0;

    for(int i = 0; i < size; i++){
        if(file[i] == '='){
            const char *strNum = &(file[i+1]);
            strncpy(strParam, strNum, 2);
            params[paramNum++] = atoi(strParam);
        }
    }
}

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
