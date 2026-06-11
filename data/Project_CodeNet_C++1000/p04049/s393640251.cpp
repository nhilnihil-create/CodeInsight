#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read()
{
	ll ans=0;ll a=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar())if(c=='-')a=-1;
	for(;c>='0'&&c<='9';c=getchar())ans=ans*10+c-48;
	return ans*a;
}
ll a[2001][2001],maxx;
vector<ll> p[2001];
ll se[2001],fi[2001],n,k,cnt;
void dfs(ll root,ll fa,ll poi,ll s)
{
	a[root][poi]=s;
	for(ll i=0;i<p[poi].size();i++) 
	{
		ll x=p[poi][i];
		if(x==fa)
		{
			continue ;
		}
		dfs(root,poi,x,s+1);
	}
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	maxx=INT_MAX;
	n=read();
	k=read();
	for(ll i=1;i<n;i++)
	{
		ll x=read();
		ll y=read();
		p[x].push_back(y);
		p[y].push_back(x);
		fi[i]=y;
		se[i]=x;
	}
	for(ll i=1;i<=n;i++)
	{
		dfs(i,-1,i,0);
	}
	for(ll i=1;i<=n;i++)
	{
		ll cnt=0;
		for(ll j=1;j<=n;j++)
		{
			if(2*a[i][j]>k)cnt++;
		}
		maxx=min(maxx,cnt);
	}
	for(ll i=1;i<n;i++)
	{
		cnt=0;
		for(ll j=1;j<=n;j++)
		{
			if(2*(min(a[j][fi[i]],a[j][se[i]]))+1>k)
			cnt++;
		}
		maxx=min(maxx,cnt);
	}
	cout<<maxx<<endl;
	return 0;
}