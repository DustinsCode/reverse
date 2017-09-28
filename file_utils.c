#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

/**
 * Functions to read and write files
 * 
 * */
int read_file( char* filename, char **buffer ){

    //This is a file stream and opens it.  "r" = open existing file for reading
    FILE* ogFile = fopen(filename, "r");

    //Get size of string
    struct stat st;
    int fileExists = stat(filename, &st);
    //size will be zero if file doesn't exist
    int size = st.st_size;

    //fseek(ogFile,0,SEEK_END);
    //int numChars = ftell(ogFile);
    //fseek(ogFile,0,0);
    *buffer = malloc(size * sizeof(char));
    fread(*buffer,sizeof(char),size,ogFile);
    fclose(ogFile);
    //for(int i = 0; i < numChars-1; i++){
    //    fseek(ogFile, i, SEEK_CUR);
    //    *buffer[i] = fgetc(ogFile);
   // }
    return size;
}

int write_file( char* filename, char *buffer, int size){
    FILE* newFile = fopen(filename, "w");

    int i = size-1;
    while(i >= 0){
        fputc(buffer[i], newFile);
        i--;
    }
    fclose(newFile);
    return 0;
}