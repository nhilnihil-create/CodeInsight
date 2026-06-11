#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int n,a[maxn],b[maxn];

inline bool jud(int x)
{
	for(int i=1;i<=2*n-1;i++) b[i]=(a[i]>=x);
	for(int l=n,r=n;l>=2;l--,r++)
	{
		if(b[l]==b[l-1]) return b[l];
		if(b[r]==b[r+1]) return b[r];
	}
	return b[1];
}

int main()
{
	n=read(); rep(i,1,2*n-1) a[i]=read();
	int l=1,r=200005,ans=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(jud(mid)) l=mid+1,ans=mid; else r=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}