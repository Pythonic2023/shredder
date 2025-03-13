#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#define HOME "/home/cipher"

/* open_dir(); Opens a directory stream for HOME and starts reading the d_name's until a NULL byte occurs. */
int open_dir(char *, char *);
int sub_dir(char *, char *);
