#include <stdio.h>

int main()
{
	char str[19];
	scanf("%s", str);

	str[5]=' ';
	str[13]=' ';
	
	printf("%s", str);
	
	return 0;
}