#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>

void over_write(const char *string_buffer, char *);

int file_type(const char *string_buffer, char *file){
	struct stat bf;
	stat(string_buffer, &bf);

	char *strptr = strrchr(string_buffer, '/');
	strptr++;

	if(strcmp(strptr, file) == 0){
		printf("Found: %s\n", strptr);
		over_write(string_buffer, file);
	}
	return 1;
}

void over_write(const char *string_buffer, char *file){
	char buffer[2]; /* Buffer to hold answer of y(es)/n(o) */
	printf("### You are being asked to overwrite a file, please proceed with caution. ###\n\n### Provide y OR n ###\n\n");
	printf("Overwrite %s at %s? ", file, string_buffer);
	
	if(fgets(buffer, 2, stdin) == NULL){
		printf("error reading");
	}
	else if(strcmp(buffer, "n") == 0){
		printf("[EXITING]\n");
	}
	else if(strcmp(buffer, "y") == 0){
		int count = 0;
		FILE *file_stream = fopen(string_buffer, "r");
		fseek(file_stream, 0, SEEK_END);
		long size = ftell(file_stream);
		fseek(file_stream, 0, SEEK_SET);
		char command_buffer[1024];
		snprintf(command_buffer, sizeof(command_buffer), "dd if=/dev/zero of=%s bs=1 count=%ld", string_buffer, size);
		
		if(system(command_buffer) == -1){
			printf("Failed to execute %s\n", command_buffer);
		}else{
			printf("\n[OVERWRITTEN]\n");
		}
			
		exit(0);
	}
	else{
		printf("[y/n]");
	}
}
