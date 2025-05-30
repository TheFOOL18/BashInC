#include "command.h"

int execute_command(char* command, queue* q){
    if(strcmp(command, "exit") == 0){
        free_queue(q);
        printf(WHT"\t\t\t\t\t\t\tExiting BashInC...\n"ESC);
        exit(0);
    }

    else if(strcmp(command, "clear") == 0){
        printf("\033[H\033[J");
        fflush(stdout);
    }

    else if(strncmp(command, "hop", 3) == 0){
        if(command[3] != '\0' && command[3] != ' '){
            return 0;
        }
        process_hop(command);
    }

    else if(strncmp(command, "reveal", 6) == 0){
        if(command[6] != '\0' && command[6] != ' '){
            return 0;
        }
        process_reveal(command);
    }    
    
    else if(strncmp(command, "log", 3) == 0){
        if(command[3] != '\0' && command[3] != ' '){
            return 0;
        }
        process_log(command, q);
    }    

    else
        return 0;

    return 1;
}

void process_command(char* command, queue* q, int type){
    char* command_copy = strdup(command);
    char* start = command_copy;
    
    if(strlen(command_copy) == 0)
        return;

    if(type == 0){
    // foreground command
        if(execute_command(command_copy, q) == 0){
            char* arg[MAX];
            char* token = strtok(command_copy, " ");
            int i = 0;
            while(token != NULL){
                arg[i] = token;
                token = strtok(NULL, " ");
                i++;
            }
            arg[i] = NULL;

            pid_t pid = fork();
            if(pid == 0){
                if(execvp(arg[0], arg) == -1){
                    printf(RED"%s: command not found\n"ESC, arg[0]);
                    exit(0);
                }
            }
            else{
                wait(NULL);
            }

        }
    }
    else if (type == 1){
    // background command
        pid_t pid = fork();
        if(pid == 0){
            printf("%s with pid: %d called\n", command_copy, getpid());
            if(execute_command(command_copy, q) == 0){
                char* arg[MAX];
                char* token = strtok(command_copy, " ");
                int i = 0;
                while(token != NULL){
                    arg[i] = token;
                    token = strtok(NULL, " ");
                    i++;
                }
                arg[i] = NULL;

                if(execvp(arg[0], arg) == -1){
                    printf("%s: command not found\n", arg[0]);
                    exit(1);
                }
            }
        }
    }
    fflush(stdout);
    free(start);
}