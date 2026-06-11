#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main(void)
{
	char s[11];
	scanf("%s", s);
	if (strncmp(s, "YAKI", 4) == 0)puts("Yes");
	else puts("No");
}