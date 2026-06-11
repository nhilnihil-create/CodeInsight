#include <stdio.h>

int main() {
    
    char a[20];
    scanf("%s", &a);
    a[5] = ' ';
    a[13] = ' ';
    
    for(int i = 0 ; a[i] != '\0'; i++){
        printf("%c", a[i]);
    }
    puts("");
    return 0;
}