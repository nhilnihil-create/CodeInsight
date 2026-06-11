#include <stdio.h>
#include <string.h>

int main(){
    char a[15], b[10], c[10];
    scanf("%s %s %s", a,b,c);
    int al = strlen(a), bl = strlen(b), cl = strlen(c);
    if (a[al-1] == b[0] && b[bl-1] == c[0]){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}