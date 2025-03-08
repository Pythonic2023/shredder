#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include "filehandle.h"

#define HOME "/home/cipher/"

int open_dir(char *file){
    char string_buffer[1024];
    struct dirent *dp;
    DIR *dir_stream = opendir(HOME);


    if(dir_stream == NULL){
        printf("failed to open dir");
    }


    while((dp = readdir(dir_stream)) != NULL){
		strcpy(string_buffer, HOME);
		strcat(string_buffer + strlen(string_buffer + 1), dp->d_name);
		file_type(string_buffer, file);
    }

    closedir(dir_stream);
}

