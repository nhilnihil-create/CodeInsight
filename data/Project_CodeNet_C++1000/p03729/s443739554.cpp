#include <stdio.h>
#include <string.h>

int main(void)
{
	int i,j;
	char a[11],b[11],c[11];

	scanf("%s %s %s",a,b,c);

	i=strlen(a)-1;
	j=strlen(b)-1;

	if((a[i]==b[0])&&(b[j]==c[0]))
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}
