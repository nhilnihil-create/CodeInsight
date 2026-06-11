#include <stdio.h>
#include <string.h>

int main(){
    char a[15];
    char b[15];
    char c [15];
    scanf("%s%s%s", a,b,c);
    int d= strlen(a)-1;
    int e = strlen(b)-1;
    if (a[d]==b[0] && b[e]==c[0]){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }

    return 0;
}