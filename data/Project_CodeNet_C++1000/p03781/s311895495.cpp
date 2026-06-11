#include<cstdio>
int n,s,t;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		s=s+i;++t;
		if (s>=n) break;
	}
	printf("%d\n",t);
	return 0;
}