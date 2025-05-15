#include "command.h"

int execute_command(char* command){
    if(strcmp(command, "exit") == 0){
        printf(WHT"\t\t\t\t\t\tExiting BashInC...\n"ESC);
        exit(0);
    }

    else if(strcmp(command, "clear") == 0){
        system("clear");
    }

    else
        return 0;

    return 1;
}

void process_command(char* command, int type){
    if(strlen(command) == 0)
        return;

    if(type == 0){
    // foreground command
        if(execute_command(command) == 0){
            char* arg[MAX];
            char* token = strtok(command, " ");
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
                    printf("%s: command not found\n", arg[0]);
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
            printf("%s with pid: %d called\n", command, getpid());
            if(execute_command(command) == 0){
                char* arg[MAX];
                char* token = strtok(command, " ");
                int i = 0;
                while(token != NULL){
                    arg[i] = token;
                    token = strtok(NULL, " ");
                    i++;
                }
                arg[i] = NULL;

                if(execvp(arg[0], arg) == -1){
                    printf("%s: command not found\n", arg[0]);
                }
            }
        }
        else{
            fflush(stdout);
        }
    }
}