#include "hop.h"

int hop(char* directory, int flag){
    char* copy = (char*)malloc(MAX);
    char* path = (char*)malloc(MAX);
    int return_value = 1;

    strcpy(copy, directory);
    getcwd(path, MAX);
    if(strcmp(copy, "-") == 0 && flag){
        if(previous_directory == NULL){
            printf(RED"Previous directory doesn't exist!\n"ESC);
            return -1;
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
        return_value = -1;
    }

    else{
        if(flag){
            if(previous_directory == NULL)
                previous_directory = (char*)malloc(MAX);
            strcpy(previous_directory, path);
        }
    }

    if(flag)
        printf("%s\n", getcwd(path, MAX));   

    free(copy);
    free(path);
    return return_value;
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
                hop(token, 1);
            }
        }
        else
            hop(token, 1);

        token = next;
    }
}