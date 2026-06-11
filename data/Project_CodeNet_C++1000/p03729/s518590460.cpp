#include <stdio.h>
#include <string.h>

int main () {
	char a [11];
	char b[11];
	char c[11];
	scanf ("%s %s %s",&a,&b,&c);
		int len1 = strlen(a);
	int len2 = strlen(b);
	
	if (a[len1-1] == b[0] && b[len2-1] == c[0]) {
		printf("YES");
	}
	else printf ("NO");

	return 0;
}