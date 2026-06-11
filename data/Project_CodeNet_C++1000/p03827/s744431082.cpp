#include <stdio.h>
#include <string.h>


int main (){

    int x;
    int n = 0;
    int big = 0;
    scanf("%d", &x);
    char string[105];
     scanf("%s", string);
    for(int i = 0; i < strlen(string); i++){
        if(string[i] == 'I'){
            n +=1;
            if(big < n) big = n;
        }else n -= 1;
    }
    printf("%d", big);



    return 0;
}