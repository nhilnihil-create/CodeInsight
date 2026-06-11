#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define inf 2333333333333333333LL

ll c1[100010],c2[100010],a[100010],n,m,ans;

inline ll rd()
{
	ll x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void modify1(int l,int r,ll x)
{
	if (l>r) return;
	c1[l]+=x;c1[r+1]-=x;
}

inline void modify2(int l,int r,ll x)
{
	if (l>r) return;
	c2[l]+=x;c2[r+1]-=x;
}

int main()
{
	n=rd();m=rd();
	for (int i=1;i<=n;i++) a[i]=rd();
	for (int i=1;i<n;i++)
	{
		int x=a[i],y=a[i+1];
		if (x==y) continue;
		if (x<y)
		{
			modify1(1,x,y-x);
			modify1(y+1,m,y-x);
			modify1(x+1,y,y+1);
			modify2(x+1,y,-1);
		}
		else
		{
			swap(x,y);
			modify1(x+1,y,m-y+x);
			modify1(1,x,x+1);
			modify1(y+1,m,m+x+1);
			modify2(1,x,-1);
			modify2(y+1,m,-1);
		}
	}
	ll ans=inf;
	for (int i=1;i<=m;i++)
	{
		c1[i]+=c1[i-1];c2[i]+=c2[i-1];
		ans=min(ans,c1[i]+c2[i]*i);
	}
	printf("%lld\n",ans);
	return 0;
}