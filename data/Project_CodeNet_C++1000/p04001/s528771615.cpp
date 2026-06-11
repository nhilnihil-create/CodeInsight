#include<stdio.h>

long long ans;
void dfs(char *s,long long num,long long tot)
{
	if(*s=='\0')
		ans+=tot+num;
	else
	{
		dfs(s+1,(*s)-48,tot+num);
		dfs(s+1,num*10+(*s)-48,tot);
	}
}
int main()
{
	char str[12];
	scanf("%s",str);
	dfs(str,0,0);
	printf("%lld",ans/2);
	return 0;
}