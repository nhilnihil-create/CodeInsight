#include <stdio.h>
#include <string.h>

int main(){
    char a[105];
    scanf("%s", a);
    char b = ' ';

    for(int i=0; i < strlen(a); i++){
        if(a[i]== ','){
            a[i] = b;
        }
    }
    printf("%s", a);
    return 0;
}