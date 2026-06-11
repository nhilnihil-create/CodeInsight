#include <stdio.h>
#include <string.h>
 
int main() {
	char a[100], b[100], c[100];
 
	scanf("%s %s %s", a, b, c);
	int x = strlen(a);
	int y = strlen(b);
	 if (a[x-1]==b[0] && b[y-1]==c[0])
	 {
	 	printf("YES\n");
	 }
	 else printf ("NO\n");
	 
	 return 0;
}
	