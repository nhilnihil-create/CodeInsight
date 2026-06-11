#include <stdio.h>
 
int main() {
	char s1[11], s2[11], s3[11];
	scanf("%s %s %s", s1, s2, s3);
	printf("%c%c%c\n", s1[0] - 32, s2[0] - 32, s3[0] - 32);
	return 0;
}