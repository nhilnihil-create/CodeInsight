#include <stdio.h>

int main(){
    int test;
    scanf("%d", &test);
    getchar();
    char word[test];
    int x = 0;
    int max = 0;
    for(int i = 0; i < test; i++){
        scanf("%c", &word[i]);
        if(word[i] == 'D'){
            x--;
        }else{
            x++;
        }
        if(x > max){
            max = x;
        }
    }
    printf("%d", max);
    return 0;
}