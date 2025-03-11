/*Include our own header files, and anything else needed*/
#include "dir_handle.h"
#include <stdlib.h>

/* Function for open dir DONE */



/* Function to search for file */



/* Function to open and overwrite the file */



/* Function to delete the file */



/* Function to search for file and return SUCCESS if not found */


/* Main */
int main(int argc, char *argv[]){
	
	if(argc < 2){
		printf("Usage: shred <file_name>\n");
		exit(-1);
	}
	open_dir(argv[1]);
}
