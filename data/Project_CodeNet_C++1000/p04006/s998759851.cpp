#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long a[5005],x,ans,k,sum,n,maxn[5005][5005];
int main()
{
	scanf("%lld%lld",&n,&x);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		a[n+i]=a[i];
		ans+=a[i];
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n+1;j++)
		{
			maxn[i][0]=a[i];
			maxn[i][j]=min(maxn[i][j-1],a[n+i-j]);
		}
	for(int i=0;i<n;i++)
	{
		sum=0;
		for(int j=1;j<=n;j++)
			sum+=maxn[j][i];
		sum+=i*x;
		ans=min(ans,sum);
	}
	printf("%lld\n",ans);
}