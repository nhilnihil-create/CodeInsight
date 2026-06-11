#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll n,k,a[maxn],p[maxn],p0[maxn],suf[maxn];

int main()
{
	n=read(); k=read(); rep(i,1,n) a[i]=read(),p[i]=p[i-1]+a[i];
	rep(i,1,n) if(a[i]>0) p0[i]=p0[i-1]+a[i]; else p0[i]=p0[i-1];
	per(i,n,1) if(a[i]>0) suf[i]=suf[i+1]+a[i]; else suf[i]=suf[i+1];
	ll ans=0;
	rep(i,k,n)
	{
		ll tmp=p0[i-k]+suf[i+1]; if(p[i]-p[i-k]>0) tmp+=(p[i]-p[i-k]);
		ans=max(ans,tmp);
	}
	cout<<ans<<endl;
	return 0;
}