#include<stdio.h>
int main()
{
	char c;
	int i=0,j=0,k=0,l=0;
	while(~scanf(" %c", &c))
	{
		if(c=='E')
			i=1;
		else if(c=='W')
			j=1;
		else if(c=='N')
			k=1;
		else if(c=='S')
			l=1;
	}
	if(i==j && k==l) printf("Yes\n");
	else printf("No\n");
	return 0;
}