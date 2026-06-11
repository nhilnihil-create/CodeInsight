#include<bits/stdc++.h>
using namespace std;
#define reg register
#define ll long long
inline ll read()
{
    ll x=0,w=0;char ch=getchar();
    while(!isdigit(ch))w|=ch=='-',ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return w?-x:x;
}
ll n,a[100005],b[100005];
inline ll gcd(ll x,ll y)
{
	ll t=y;if(x<y)swap(x,y);
	while(y)
	{
		t=x%y;
		x=y;y=t;
	}
	return x;
}
inline bool dfs()
{
	memset(b,0,sizeof b);
	ll fl=0,g=0;
	for(reg ll i=1;i<=n;++i)
	{
		if(a[i]&1)a[i]--;
		if(g==0)g=a[i];
		g=gcd(g,a[i]);
	}
	for(reg ll i=1;i<=n;++i)
	{
		a[i]/=g,b[a[i]&1]++;
		if(a[i]==1)fl=1;
	}
	if(fl)
	{
		if(b[0]&1) return true;
		else return false;
	}
	if(b[0]&1) return true;
	else
	{
		if(b[1]==1)return !dfs();
		else return false;
	}
}
int main()
{
    n=read();ll fl=0;
	for(reg ll i=1;i<=n;++i)
	{
		a[i]=read(),b[a[i]&1]++;
		if(a[i]==1)fl=1;
	}
	if(fl)
	{
		if(b[0]&1)puts("First");
		else puts("Second");
		return 0;
	}
	if(b[0]&1)puts("First");
	else
	{
		if(b[1]==1)
			puts(!dfs()?"First":"Second");
		else puts("Second");
	}
    return 0;
}
