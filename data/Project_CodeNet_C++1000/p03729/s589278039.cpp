#include <stdio.h>
#include <string.h>

int main(){
	char a[11], b[11], c[11];
	scanf("%s %s %s", a,b,c);
	int d=strlen(a)-1,e=strlen(b)-1;
	if(a[d]==b[0] && b[e]==c[0]){
		puts("YES");
	}else{
		puts("NO");
	}
	
	
	return 0;
}