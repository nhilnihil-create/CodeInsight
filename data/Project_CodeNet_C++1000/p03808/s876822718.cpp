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

ll tot,n,a[maxn],c,k,d[maxn],f;

int main()
{
	n=read(); rep(i,1,n) a[i]=read(),tot+=a[i]; c=n*(n+1)/2;
	if(tot%c!=0) return puts("NO"),0; k=tot/c;
	rep(i,2,n) d[i]=a[i]-a[i-1]; d[1]=a[1]-a[n];
	rep(i,1,n) if((k-d[i])%n!=0||d[i]>k) f=1;
	printf(f?"NO":"YES");
	return 0;
}