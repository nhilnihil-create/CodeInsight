#include<stdio.h>
int main(){
    char str[20];
    scanf("%[^\n]",&str);
    str[5]= ' ';
    str[13]= ' ';
    printf("%s", str);
    return 0;
    
}