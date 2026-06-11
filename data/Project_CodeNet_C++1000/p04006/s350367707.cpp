#include<iostream>
#include<string.h>
#include<cstdio>
using namespace std;
long long a[2010],b[2010][2010],n,m,ans=2000000000010,cnt;
int main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) 
	{
		scanf("%lld",&a[i]);
		b[0][i]=a[i];
	}
	for(int i=1;i<n;i++)
		for(int j=1;j<=n;j++)
			b[i][j]=2000000000010;
	for(int i=1;i<n;i++)
		for(int j=1;j<=n;j++)
		{
			int k=(j-i)%(n+1);
			if(k<=0) k+=n;
			b[i][j]=min(b[i-1][j],a[k]);
		}
	for(int i=0;i<n;i++)
	{
		cnt=i*m;
		for(int j=1;j<=n;j++)
			cnt+=b[i][j];
	    ans=min(ans,cnt);
	}
	printf("%lld",ans);
	return 0;
}