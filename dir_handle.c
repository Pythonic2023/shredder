#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include "filehandle.h"

#define HOME "/home/cipher/"

void open_dir(char *file, char *directory){
	struct dirent *dp;
	struct stat bf;
	DIR *dir_stream = opendir(directory);
	char full_path[1024];
	
	if(!dir_stream){
		return;
	}	
	
	while((dp = readdir(dir_stream)) != NULL){
		if(strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0){
			continue;
		}
	
		snprintf(full_path, sizeof(full_path), "%s/%s", directory, dp->d_name);

		if(stat(full_path, &bf) == 0 && S_ISREG(bf.st_mode)){
			file_type(full_path, file);
		}
	}
	
	rewinddir(dir_stream);
	
	while((dp = readdir(dir_stream)) != NULL){
		if(strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0){
			continue;
		}
	
		snprintf(full_path, sizeof(full_path), "%s/%s", directory, dp->d_name);

		if(stat(full_path, &bf) == 0 && S_ISDIR(bf.st_mode)){
			open_dir(file, full_path);
		}
	}
	closedir(dir_stream);
	return;
}
