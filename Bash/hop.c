#include "hop.h"

void hop(char* directory){
    char* copy = (char*)malloc(MAX);
    char* path = (char*)malloc(MAX);

    strcpy(copy, directory);
    getcwd(path, MAX);
    if(strcmp(copy, "-") == 0){
        if(previous_directory == NULL){
            printf(RED"Previous directory doesn't exist!\n"ESC);
            return ;
        }
        strcpy(copy, previous_directory);
    }

    if(directory[0] == '~'){
        strcpy(copy, "/home/");
        strcat(copy, getlogin());
        strcat(copy, directory+1);
    }

    if(chdir(copy) == -1){
        printf(RED"Folder does not exist!\n"ESC);
    }
    else{
        if(previous_directory == NULL)
            previous_directory = (char*)malloc(MAX);
        strcpy(previous_directory, path);
    }
    printf("%s\n", getcwd(path, MAX));   

    free(copy);
    free(path);
}

void process_hop(char* command){
    char* copy = strdup(command);
    char* token = strtok(copy, " ");
    char* next;

    bool first_token = true;
    while(token){
        next = strtok(NULL, " ");
        if(first_token){
            first_token = false;
            if(next == NULL){
                strcpy(token, "~");
                hop(token);
            }
        }
        else
            hop(token);

        token = next;
    }
}