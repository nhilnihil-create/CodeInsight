#include <stdio.h>
int main (){
    	
    int ctr = 0;
    int n;
    scanf("%d\n", &n);
    char s[n];
   	scanf("%s", s);
    int temp = 0;
    	
    for (int i=0; i<n; i++){
    	if (s[i] == 'I')ctr++;
    	if (s[i] == 'D')ctr--;
    	if (ctr > temp) temp++;
    }
    printf("%d", temp);	
    return 0;
}