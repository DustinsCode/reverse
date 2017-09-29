/*******************************************************
 * Reverse project for CIS 343.  Takes the contents
 * of a file and writes them in reverse into a new 
 * file
 * 
 * @author Dustin Thurston
 * @date 9/29/2017
 *******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "file_utils.h"
#include <sys/stat.h>

/*********************************************************
 * Controls the program flow
 * 
 * @args name of file to be reversed and file to create
 * *******************************************************/
int main(int argc, char** argv){

        /* Buffer for storing contents of file */
        char* buffer;
        
        //Check that two arguments are made
        if(argc != 3){
                fprintf(stderr, "TWO FILE NAMES MUST BE PROVIDED \n");
                return -1;
        }

        //Reads file and returns -1 if file doesn't exist
        int read = read_file(argv[1], &buffer);
        if(read < 0){
                fprintf(stderr, "FILE DOES NOT EXIST\n");
                return -1;
        }

        //Writes contents of buffer in reverse to a new file
        int write = write_file(argv[2], buffer, read);

        printf("File reversed successfully\n");
        free(buffer);
}