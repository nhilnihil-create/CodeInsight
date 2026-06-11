#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll n,a[maxn];

int main()
{
	n=read(); rep(i,1,n) a[i]=read();
	ll nw=0,ans=0;
	rep(i,1,n)
	{
		if(a[i]==0) nw=0;
		else
		{
			if(nw) a[i]++,ans+=(a[i]/2),nw=a[i]%2;
			else ans+=(a[i]/2),nw=a[i]%2;
		}
	}
	cout<<ans<<endl;
	return 0;
}