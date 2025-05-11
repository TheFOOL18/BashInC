#include "display.h"

char* get_path(){
    char *path = (char*)malloc(MAX);
    char* tilda = (char*)malloc(MAX);
    getcwd(path, MAX);
    strcpy(tilda, "/home/");
    strcat(tilda, getlogin());
    if(strstr(path, tilda)){
        path += strlen(tilda) - 1;
        path[0] = '~';
    }
    return path;
    free(tilda);
}

void display(){
    char* host = (char*)malloc(MAX);
    gethostname(host, MAX);
    printf(GRN"%s@%s"ESC, getlogin(), host);
    printf(":");

    printf(MGN"%s"ESC, get_path());
    printf("$ ");
    free(host);
}