#include <stdio.h>
#include <string.h>
int main(){
    char a[11], b[11], c[11];
    scanf("%s %s %s", a, b, c);
    int lenA = strlen(a);
    int lenB = strlen(b);
    int lenC = strlen(c);
    if (a[lenA-1] == b[0] && b[lenB-1] == c[0]){
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }





return 0;
}
