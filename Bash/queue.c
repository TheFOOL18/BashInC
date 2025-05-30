#include "queue.h"

queue* init_queue(){
    queue* q = (queue*)malloc(sizeof(queue));
    for(int i=0;i<QUEUE_SIZE;i++){
        q->commands[i] = (char*)malloc(MAX);
        q->commands[i][0] = '\0';
        q->size = 0;
    }
    return q;
}

queue* enqueue(queue* q, char* command){
    if(q->size < QUEUE_SIZE){
        strcpy(q->commands[q->size], command);
        q->size++;
    }

    else{
        if(queue_command == NULL) queue_command = (char*)malloc(MAX);
        strcpy(queue_command, q->commands[0]);
        for(int i=1;i<QUEUE_SIZE;i++){
            strcpy(q->commands[i-1], q->commands[i]);
        }
        strcpy(q->commands[QUEUE_SIZE-1], command);
    }
    write_log(q);
    return q;
}

queue* pop(queue* q){
    strcpy(q->commands[q->size-1], "\0");
    if(q->size != QUEUE_SIZE || queue_command == NULL) q->size --;
    else{
        for(int i = QUEUE_SIZE-2;i>=0;i--)
            strcpy(q->commands[i+1], q->commands[i]);

        strcpy(q->commands[0], queue_command);
    }

    write_log(q);
    return q;
}

queue* clear_queue(queue* q){
    for(int i=0;i<QUEUE_SIZE;i++){
        strcpy(q->commands[i], "\0");
    }
    q->size = 0;
    free(queue_command);
    write_log(q);
    return q;
}

void* show_queue(queue* q){
    for(int i=0;i<q->size;i++){
        printf("%d) %s\n", i+1, q->commands[i]);
    }
}

void free_queue(queue* q){
    for(int i=0;i<QUEUE_SIZE;i++){
        free(q->commands[i]);
    }
    free(q);
}