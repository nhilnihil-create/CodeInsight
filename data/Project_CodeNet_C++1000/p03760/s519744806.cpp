#include<stdio.h>
#include<string.h>
int main()
{
	char a[51], b[51];
	scanf("%s %s", a,b);
	int i,l=strlen(b);
	for(i=0; i<l; i++)
		printf("%c%c", a[i], b[i]);
	if(strlen(a)==l+1)
		printf("%c", a[i]);
	return 0;
}