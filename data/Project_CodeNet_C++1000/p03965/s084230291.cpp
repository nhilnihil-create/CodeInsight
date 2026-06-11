#include<cstdio>
#include<cstring>
char s[1001000];
int main ()
{
	scanf("%s",s);
	int len=strlen(s),ag=0,me=len/2 ;
	for(int i=0;i<len;i++)
	{
		if(s[i]=='p')
			ag++;
	}
	printf("%d",me-ag);
}