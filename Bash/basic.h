#ifndef BASIC_H
#define BASIC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <sys/utsname.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BLK "\e[1;30m"
#define RED "\e[1;31m"
#define GRN "\e[1;32m"
#define YEL "\e[1;33m"
#define MGN "\e[1;34m"
#define PINK "\e[1;35m"
#define BLU "\e[1;36m"
#define WHT "\e[1;37m"
#define ESC "\e[0m"

#define MAX 1024

extern char* previous_directory;
extern char* log_path;
extern char* queue_command;

char* trim(char* str);

#endif