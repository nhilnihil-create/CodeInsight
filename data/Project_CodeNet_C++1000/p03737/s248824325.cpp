#include <stdio.h>
int main(void){
    // Your code here!
    char str[11];
    
    for(int i = 0;i < 3;i++){
        scanf("%10s",str);
        printf("%c",str[0]-'a'+'A');
    }
}
