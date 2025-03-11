#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include "filehandle.h"

#define HOME "/home/cipher/"

void sub_dir(char *);

void open_dir(char *file){
    char string_buffer[1024];
    struct dirent *dp;
	struct stat bf;
    DIR *dir_stream = opendir(HOME);
	

    if(dir_stream == NULL){
        printf("failed to open dir");
		return;
    }
	
	while((dp = readdir(dir_stream)) != NULL){
		if(strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0){
			continue;
		}
		strcpy(string_buffer, HOME);
		strcat(string_buffer + strlen(string_buffer +1), dp->d_name);
		sub_dir(string_buffer);
	}
	closedir(dir_stream);
}

void sub_dir(char *directory){
	struct dirent *dp;
	struct stat bf;
	DIR *dir_stream = opendir(directory);
	
	if(!dir_stream){
		return;
	}	
	
	while((dp = readdir(dir_stream)) != NULL){
		if(strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0){
			continue;
		}
	
		char path[1024];
		snprintf(path, sizeof(path), "%s/%s", directory, dp->d_name);

		if(stat(path, &bf) == -1){
			printf("stat error");
			continue;
		}

		if(S_ISREG(bf.st_mode)){
			/*printf("regular file: %s\n", dp->d_name);*/
			file_type(path);
		}else if(S_ISDIR(bf.st_mode)){
			/*printf("Directory: %s\n", dp->d_name);*/
			sub_dir(path);
		}
	}
	return;
}
