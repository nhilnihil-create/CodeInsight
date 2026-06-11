#include <stdio.h>

int main () {
	char a[25];
	scanf("%s", &a);
	a[5] = ' ';
	a[13] = ' ';
	printf("%s\n", a);
	return 0;
}