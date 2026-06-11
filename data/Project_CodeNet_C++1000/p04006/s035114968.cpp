#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 4005
#define inf 1e18
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

ll n,a[maxn],x,mn[maxn][maxn],ans;

int main()
{
	n=read(); x=read(); rep(i,1,n) a[i]=read(),a[n+i]=a[i],mn[i][i]=a[i];
	rep(i,(n+1),2*n) mn[i][i]=a[i];
	rep(i,1,2*n) rep(j,(i+1),2*n) mn[i][j]=min(mn[i][j-1],a[j]); ans=inf;
	for(int k=0;k<=n-1;k++)
	{
		ll tmp=k*x;
		for(int i=1;i<=n;i++) tmp+=mn[i-k+n][i+n];
		ans=min(ans,tmp);
	}
	cout<<ans<<endl;
	return 0;
}