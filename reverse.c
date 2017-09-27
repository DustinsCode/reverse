#include <stdio.h>
#include "file_utils.h"
#include <sys/stat.h>

int main(int argc, char** argv){
    //argv[1] = file to be read
    //argv[2] = file to be written

    //Get size of file
    struct stat st;
    stat(argv[1], &st);
    int size = st.st_size;

    char** buffer = malloc(50*sizeof(size));
    int read = read_file(argv[1], **buffer);

}
