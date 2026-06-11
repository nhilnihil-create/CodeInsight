#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#define ll long long
using namespace std;
ll n,m,i,j,k,l,o,p,ans,ans1;
vector<ll> v[10010];
struct E
{
	ll x,y;
}a[10010];
void dfs(ll x,ll y,ll de)
{
	if (de>k/2) ans++;
	for (ll i=0;i<v[x].size();i++)
	 if (v[x][i]!=y)
	  dfs(v[x][i],x,de+1);
}
int main()
{
	scanf("%lld%lld",&n,&k);
	for (i=1;i<n;i++)
	{
		ll x,y;
		scanf("%lld%lld",&x,&y);
		E t;
		t.x=x;t.y=y;
		a[i]=t;
		v[x].push_back(y);
		v[y].push_back(x);  
	}
	ans1=1e9;
	if (k%2==0)
	{
		for (i=1;i<=n;i++)
		 {
		 	ans=0;
		 	dfs(i,-1,0);
		 	ans1=min(ans,ans1);
		 }
	}
	else
	{
		for (i=1;i<n;i++)
		{
			ans=0;
		 	dfs(a[i].x,a[i].y,0);
		 	dfs(a[i].y,a[i].x,0);
		 	ans1=min(ans,ans1);
		}
	}
	printf("%lld\n",ans1);
}
