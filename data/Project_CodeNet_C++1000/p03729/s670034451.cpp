#include <stdio.h>
#include <string.h>
 
int main(){
    char a[26] ,b[26], c[26];
    scanf("%s %s %s", &a, &b, &c);
 
    int x = strlen(a), y = strlen(b);
    if(a[x-1] == b[0] && b[y-1] == c[0]){
        printf("YES \n");
    }else {
        printf("NO \n");
    }
    return 0;
}