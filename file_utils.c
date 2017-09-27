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

    /**
    for(int i = 0; i < size; i++){
        buffer[i] = ogFile
    }
    */ 

    return 0;
}

int write_file( char* filename, char *buffer, int size){
    return 0;
}