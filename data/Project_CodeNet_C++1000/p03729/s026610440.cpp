#include <stdio.h>
#include <string.h>

int main (){
    char a[12];
    char b[12];
    char c[12];
    
    scanf("%s %s %s", &a, &b, &c);
    int k = strlen (a); 
    int t = strlen (b); 
    int f = strlen (c);
    if (a[k-1] == b[0] && b[t-1] == c[0]) {
        printf("YES\n");
    } 
	else {
        printf("NO\n");
    }
    
    return 0;
}