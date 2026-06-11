#include<stdio.h>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<bitset>
#include<vector>
#include<math.h>
#include<stack>
#include<map>
#include<queue>
#define ls(x) (x<<1)
#define rs(x) ((x<<1)|1)
#define eps 1e-9
using namespace std;
long long n,m;
long long a[100005];
long long b[100005],c[100005];
int main()
{
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	long long ans=0;
	for(long long i=1;i<n;i++)
	{
		if(a[i+1]>a[i])
		{
			ans+=a[i+1]-a[i];
			b[a[i]+2]++;
			b[a[i+1]+1]--;
			c[a[i+1]+1]-=(a[i+1]-a[i]-1);
		}
		else
		{
			ans+=m-a[i]+a[i+1];
			b[a[i]+2]++;
			b[2]++;
			b[a[i+1]+1]--;
			c[1]+=m-a[i];
			c[a[i+1]+1]-=a[i+1]+m-a[i]-1;
		}
	}
	//cout<<ans<<endl;
	for(long long i=1;i<=m;i++)
	{
		b[i]+=b[i-1];
		//cout<<i<<' '<<b[i]<<endl;
	}
	long long mx=0;
	for(long long i=1;i<=m;i++)
	{
		c[i]+=c[i-1]+b[i];
		//cout<<i<<' '<<c[i]<<endl;
		mx=max(mx,c[i]);
	}
	printf("%lld\n",ans-mx);
}