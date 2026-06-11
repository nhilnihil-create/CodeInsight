#include<stdio.h>
#include<string.h>
int main()
{
	char a[101], b[101];
	int la, lb;
	scanf("%s", a);
	scanf("%s", b);
	la = strlen(a);
	lb = strlen(b);
	if(la>lb)
		printf("GREATER");
	else if(la<lb)
		printf("LESS");
	else
	{
		if(strcmp(a,b)==0)
			printf("EQUAL");
		else if(strcmp(a,b)<0)
			printf("LESS");
		else
			printf("GREATER");
	}
	return 0;
}