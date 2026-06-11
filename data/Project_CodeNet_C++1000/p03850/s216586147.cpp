#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int a[101010];
long long sum[101010];
char s[101010][2];
int la;
int ne[101010];
int main()
{
	int n;
	long long now=0,ans=-1010101010101010ll;
	scanf("%d%d",&n,&a[1]);
	s[1][0]='+';
	la=0;
	for(int i=2;i<=n;i++)
	{
		scanf("%s%d",s[i],&a[i]);
		if(s[i][0]=='-')
		{
			ne[la]=i;
			la=i;
		}
	}
	ne[la]=n+1;
	sum[0]=0;
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		if(s[i][0]=='+')
			now+=a[i];
		else
		{
			ans=max(ans,now+sum[n]-sum[ne[i]-1]-(sum[ne[i]-1]-sum[i-1]));
			now-=a[i];
		}
	}
	ans=max(ans,now);
	printf("%lld",ans);
	return 0;
}