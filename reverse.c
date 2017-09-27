#include <stdio.h>
#include <stdlib.h>
#include "file_utils.h"
#include <sys/stat.h>

int main(int argc, char** argv){
    
    //Get size of string
    struct stat st;
    stat(argv[1], &st);
    int size = st.st_size;

    char** buffer = malloc(size * sizeof(char));

    int read = read_file(argv[1], buffer);
    printf("%d",size);
}
