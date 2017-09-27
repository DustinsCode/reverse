#include <stdio.h>
#include <stdlib.h>
#include "file_utils.h"
#include <sys/stat.h>

int main(int argc, char** argv){
<<<<<<< HEAD
    //argv[1] = file to be read
    //argv[2] = file to be written

    //Get size of file
=======
    
    //Get size of string
>>>>>>> 32f4fb23c5eaa9fc2f7b725558e35c7c948f4aaa
    struct stat st;
    stat(argv[1], &st);
    int size = st.st_size;

<<<<<<< HEAD
    char** buffer = malloc(50*sizeof(size));
    int read = read_file(argv[1], **buffer);

=======
    char** buffer = malloc(size * sizeof(char));

    int read = read_file(argv[1], buffer);
    printf("%d",size);
>>>>>>> 32f4fb23c5eaa9fc2f7b725558e35c7c948f4aaa
}
