#include <stdio.h>
#include <stdlib.h>
#include "file_utils.h"
#include <sys/stat.h>

int main(int argc, char** argv){

        char* buffer;
        
        int read = read_file(argv[1], &buffer);
        int write = write_file(argv[2], buffer, read);

        printf("%d \n",read);
        free(buffer);
    
}