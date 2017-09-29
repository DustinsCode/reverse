#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

/***********************************************************
 * Function to read the contents of a file
 * into a buffer
 * 
 * @param filename character array containing file name 
 *        to be read
 * @param **buffer reference to pointer of buffer for data
 * @return Either the size of the file read or -1 for an error
 **********************************************************/
int read_file( char* filename, char **buffer ){

    //This is a file stream and opens it.  "r" = open existing file for reading
    FILE* ogFile = fopen(filename, "r");

    //Get size of string
    struct stat st;
    int fileExists = stat(filename,&st);
    //size will be zero if file doesn't exist
    int size = st.st_size;
    if(size == 0){
        return -1;
    }

    //Allocates memory to buffer and reads data to it
    *buffer = malloc(size * sizeof(char));
    fread(*buffer,sizeof(char),size,ogFile);
    fclose(ogFile);

    return size;
}

/******************************************************************
 * Function to write the contents from a buffer to a file
 * in reverse.
 * 
 * @param filename name of file to be created and written to
 * @param *buffer pointer to buffer to write from
 * @param size the size of the previous file
 * @return 0 if successful
 *****************************************************************/
int write_file( char* filename, char *buffer, int size){

    //creates file and write information to it
    FILE* newFile = fopen(filename, "w");
    int i = size-1;
    while(i >= 0){
        fputc(buffer[i], newFile);
        i--;
    }
        
    fclose(newFile);
    return 0;
}