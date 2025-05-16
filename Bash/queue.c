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
        for(int i=1;i<QUEUE_SIZE;i++){
            strcpy(q->commands[i-1], q->commands[i]);
        }
        strcpy(q->commands[QUEUE_SIZE-1], command);
    }

    return q;
}

queue* clear_queue(queue* q){
    for(int i=0;i<QUEUE_SIZE;i++){
        strcpy(q->commands[i], "c");
    }
    q->size = 0;
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
}