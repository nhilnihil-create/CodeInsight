#include <stdio.h>
int main(){
    char str[25];
    scanf("%[^\n]", str);

    for (int i=0; str[i] != '\0'; i++){
        if (i == 5 || i == 13){
            printf(" ");
        }
        else
        {
            printf("%c", str[i]);
        }
    }
    return 0;
}
