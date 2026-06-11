#include <stdio.h>
#include <string.h>

int main() {
	
	char a[11],b[11],c[11];
	
	scanf("%s %s %s",&a,&b,&c);
	
	int p = strlen(a), q = strlen(b);
	
	
	if(a[p-1] == b[0] && b[q-1] == c[0]){
		puts("YES");
	}else{
		puts("NO");
	}
	



	return 0;
}
