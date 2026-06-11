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

int a[505][505],nw[505],cnt[505],n,m,v[505];

inline bool jud(int x)
{
	rep(i,1,n) nw[i]=1; rep(i,0,m) cnt[i]=0,v[i]=0;
	rep(i,1,m)
	{
		int tmp=0;
		rep(j,1,n) cnt[a[j][nw[j]]]++;
		rep(j,1,m) tmp=max(tmp,cnt[j]);
		if(tmp<=x) return true;
		rep(j,1,m) if(cnt[j]>x) v[j]=1;
		rep(j,1,n)
		{
			cnt[a[j][nw[j]]]--;
			if(v[a[j][nw[j]]])
			{
				while(v[a[j][nw[j]]]&&nw[j]<=m+1) nw[j]++;
				if(nw[j]>=m+1) return false;
			}
		}
	}
}

int main()
{
	n=read(); m=read(); rep(i,1,n) rep(j,1,m) a[i][j]=read();
	int l=1,r=n,ans=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(jud(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans<<endl;
	return 0;
}