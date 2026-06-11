#include <stdio.h>
#include <string.h>

int main() {
	char a[255], b[255], c[255];
	scanf("%s %s %s", &a, &b, &c);
	int lena = strlen(a);
	int lenb = strlen(b);
	int lenc = strlen(c);
	
	if(a[lena - 1] == b[0] && b[lenb - 1] == c[0]){
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}
	return 0;
}