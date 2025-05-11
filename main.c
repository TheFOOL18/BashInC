#include "basic.h"
#include "display.h"

int main(){
    while(true){
        char* str = (char*)malloc(MAX);
        int i = 0;
        while(i < MAX - 1){
            scanf("%c", &str[i]);
            if(str[i] == '\n'){
                str[i] = '\0';
                break;
            }
            i++;
        }
        if(strcmp(str, "exit") == 0){
            free(str);
            break;
        }

        display();
        str = trim(str);
        char dummy[MAX];
        // printf("%s\n", dummy);
    }
}