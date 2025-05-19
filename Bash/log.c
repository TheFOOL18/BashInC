#include "log.h"

void init_log(queue* q){
    log_path = (char*)malloc(MAX);
    getcwd(log_path, MAX);
    strcat(log_path, "/log.txt");
    FILE* f = freopen(log_path, "r", stdin);

    if(!f){
        f = freopen(log_path, "w+", stdin);
        fclose(f);
        freopen("/dev/tty", "r", stdin);
        return ;
    }

    char* s = (char*)malloc(MAX);
    int i = 0;
    
    while (i<QUEUE_SIZE){
        if (fgets(s, MAX, stdin) != NULL) {
            if(strlen(s) == 0) break;
            s[strcspn(s, "\n")] = '\0';
        }
        else break;
        strcpy(q->commands[i], s);
        i++;
    }
    q->size = i;
    fclose(f);
    freopen("/dev/tty", "r", stdin);
    free(s);
}

void write_log(queue* q){
    int fd = open(log_path, O_WRONLY | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open log.txt");
        return;
    }
    int std_out = dup(STDOUT_FILENO);
    dup2(fd, STDOUT_FILENO);
    for(int i=0;i<q->size;i++){
        printf("%s\n", q->commands[i]);
        fflush(stdout);
    }
    dup2(std_out,STDOUT_FILENO);
    close(fd);
}

void process_log(char* command, queue* q){
    char* copy = strdup(command);
    char* token = strtok(copy, " ");
    char* next;
    bool first_token = true;
    bool execute = false;

    while(token){
        next = strtok(NULL, " ");
        if(first_token){
            first_token = false;
            if(next == NULL){
                q = pop(q);
                show_queue(q);
            }
        }

        else if(!execute && strcmp(token, "purge") == 0){
            if(next == NULL) q = clear_queue(q);
            
            else{
                printf(RED"Invalid command!\n"ESC);
                return ;
            }
        }

        else if(!execute && strcmp(token, "execute") == 0) execute = true;

        else if(!execute){
            printf(RED"Invalid command!\n"ESC);
            return ;
        }

        else if(execute){
            if(next == NULL){
                int idx = atoi(token);
                if(idx > q->size-1){
                    printf(RED"error: execute index out of bounds!\n"ESC);
                    return;
                }
                q = pop(q);
                printf("Executing command: %s\n", q->commands[q->size-idx]);
                return split_command(q->commands[q->size-idx], q);
            }

            else{
                printf(RED"Invalid command!\n"ESC);
                return ;
            }
        }

        token = next;
    }
}