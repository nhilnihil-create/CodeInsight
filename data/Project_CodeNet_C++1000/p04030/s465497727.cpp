#include <stdio.h>
int main(){
    char input[100];
    scanf("%s", input);
    char reset[100];
    int id = 0;
    for(int i = 0; input[i] != '\0'; i++){
        if(input[i] == '0'){
            reset[id] = '0';
            id++;
        }
        if(input[i] == '1'){
            reset[id] = '1';
            id++;
        }
        if(input[i] == 'B'){
            if(id > 0){
                id--;
                reset[id] = '\0';
            }
        }
    }
    reset[id] ='\0';
    printf("%s\n", reset);
    return 0;
}