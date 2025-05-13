#include "basic.h"
#include "display.h"
#include "split_command.h"

int main(){
    printf(WHT"\t\t\t\t\t\tStarting BashInC...\n"ESC);
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
        split_command(str);
    }
    return 0;
}