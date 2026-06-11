#include<stdio.h>
 
int main(){
    char s[25];
    scanf("%s", s);
    for(int i = 0; i<20; i++){
        if(s[i]==','){
            s[i] = ' ';
        }
    }
    printf("%s", s);
}   