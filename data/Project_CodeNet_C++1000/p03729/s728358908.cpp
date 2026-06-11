#include <stdio.h>
#include <string.h>
int main(){
	char a[11];
	char b[11];
	char c[11];
	scanf("%s %s %s", &a,&b,&c);
	int d = strlen(a);
	int e = strlen(b);
	if(a[d-1]==b[0]&&b[e-1]==c[0]){
		printf("YES");
	}else{
		printf("NO");
	}
return 0;
}