#include "basic.h"
#include "display.h"
#include "split_command.h"
#include "queue.h"

int main(){
    printf(WHT"\t\t\t\t\t\t\tStarting BashInC...\n"ESC);
    queue* q = init_queue();
    while(true){
        char* str = (char*)malloc(MAX);
        display();
        int i = 0;
        while(i < MAX - 1){
            scanf("%c", &str[i]);
            if(str[i] == '\n'){
                str[i] = '\0';
                break;
            }
            i++;
        }
        if(q->size == 0 || (q->size > 0 && strcmp(q->commands[q->size-1], str)))
            q = enqueue(q, str);

        split_command(str, q);
    }
    return 0;
}