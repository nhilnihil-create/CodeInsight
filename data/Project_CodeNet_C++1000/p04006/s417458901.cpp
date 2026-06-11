#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<stack>
#include<map>
#include<deque>
#include<set>
#define inf 1e18
#define eps 1e-6
#define N 4020
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline ll read()
{
	char ch=getchar();
	ll s=0,w=1;
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return s*w;
}
ll a[N],minn[N][N];
ll ans=inf;
ll n,x;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),x=read();
	for(register int i=1;i<=n;i++)a[i]=a[i+n]=read();
	for(register int i=1;i<=(n<<1);i++)
	{
		minn[i][i]=a[i];
		for(register int j=i+1;j<=(n<<1);j++)minn[i][j]=min(minn[i][j-1],a[j]);
	}
	for(register int k=0;k<n;k++)
	{
		ll sum=0;
		for(register int i=n+1;i<=2*n;i++)sum+=minn[i-k][i];
		sum+=k*x;ans=min(ans,sum);
	}
	printf("%lld\n",ans);
	return 0;
}
