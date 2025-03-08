#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>

void over_write(const char *string_buffer, char *);

char *file_type(const char *string_buffer, char *file){
	struct stat bf;
	stat(string_buffer, &bf);

	if(S_ISREG(bf.st_mode)){
		char *strptr = strrchr(string_buffer, '/');
		strptr++;

		if(strcmp(strptr, file) == 0){
			/*printf("Found: %s\n", strptr);*/
			over_write(string_buffer, file);
		}

		}
}

void over_write(const char *string_buffer, char *file){
	char buffer[2]; /* Buffer to hold answer of y(es)/n(o) */
	printf("### You are being asked to overwrite a file, please proceed with caution. ###\n\n### Provide y OR n ###\n\n");
	printf("Overwrite %s at %s?\n", file, string_buffer);
	
	if(fgets(buffer, 2, stdin) == NULL){
		printf("error reading");
	}
	else if(strcmp(buffer, "n") == 0){
		printf("[EXITING]\n");
	}
	else if(strcmp(buffer, "y") == 0){
		printf("[OVERWRITING...]\n");
	}
	else{
		printf("[y/n]");
	}
}
