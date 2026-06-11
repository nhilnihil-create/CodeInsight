#include <stdio.h>
#include <string.h>

int main(){
    
    char a[15], b[15], c[15];
    scanf("%s", a);
	scanf("%s", b);
	scanf("%s", c);
	
	int lena = strlen(a);
	int lenb = strlen(b);
	int lenc = strlen(c);
	
	if(a[lena-1] == b[0] && b[lenb-1] == c[0]){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
	
	return 0;
}