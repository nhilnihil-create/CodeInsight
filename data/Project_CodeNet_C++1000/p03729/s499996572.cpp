#include <stdio.h>
#include <string.h>
 
int main(){
	char a[11], b[11], c[11];
	scanf("%s %s %s", &a, &b, &c);
	int lena=strlen(a);
	int lenb=strlen(b);
	
	if(a[lena-1]==b[0] && b[lenb-1] == c[0]){
		printf("YES");
	}
	else {
		printf("NO");
	}
	
	return 0;
}