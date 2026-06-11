#include<cstdio>
#include<iostream>
#include<algorithm>
#define ll long long
#define maxn 55

using namespace std;

ll a[maxn];
ll f[maxn][maxn];
ll ans1,ans2,n,m,k,js,jsq;

ll cmp(ll a,ll b)
{
	return a>b;
}

int main()
{
	f[0][0]=1;
	for(int i=1;i<=50;i++)
	{
		f[i][0]=1;
		f[i][i]=1;
		for(int j=1;j<=i;j++)
		{
			f[i][j]=f[i-1][j]+f[i-1][j-1];
		}
	}
	scanf("%lld%lld%lld",&n,&m,&k);
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	for(ll i=1;i<=m;i++)
	{
		ans1+=a[i];
	}
	for(ll i=1;i<=n;i++)
	{
		if(a[m]==a[i])
		{
			js++;
		}
	}
	for(ll i=1;i<=m;i++)
	{
		if(a[m]==a[i])
		{
			jsq++;
		}
	}
	if(a[m]==a[1])
	{
		for(ll i=m;i<=min(k,js);i++)
		{
			ans2+=f[js][i];
		}
	}
	if(a[m]!=a[1])
	{
		ans2=f[js][jsq];
	}
	printf("%lf\n%lld",(double)ans1/m,ans2);
	return 0;
}