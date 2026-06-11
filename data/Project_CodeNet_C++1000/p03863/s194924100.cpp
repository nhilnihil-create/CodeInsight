#include <cstdio>

int n,ans;

char ch[100002];

int main()
{
	scanf("%s",ch);
	while(ch[n])++n;
	--n;
	if((ch[0]==ch[n])^((n+1)%2))
		printf("First\n");
	else printf("Second\n");
	return 0;
}