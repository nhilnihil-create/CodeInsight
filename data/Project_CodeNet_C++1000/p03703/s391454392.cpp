#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define int long long
#define rint register int
using namespace std;
const int maxn=2e5+5;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int n,k;
int a[maxn];
int sum[maxn];
int ans;
int c[maxn];
inline void msort(int l,int r)
{
	if(l==r)
	return ;
	int mid=(l+r)>>1;
	msort(l,mid);
	msort(mid+1,r);
	int i=l,j=mid+1,k=l;
	while(i<=mid&&j<=r)
	{
		if(a[i]<=a[j])
		{
			ans+=r-j+1;
			c[k++]=a[i++];
		}
		else
		c[k++]=a[j++];
	}
	while(i<=mid)
	c[k++]=a[i++];
	while(j<=r)
	c[k++]=a[j++];
	for(int i=l;i<=r;i++)
	a[i]=c[i];
}
signed main()
{
	n=read()+1;
	k=read();
	for(rint i=2;i<=n;i++)
	{
		a[i]=read();
		sum[i]=sum[i-1]+a[i];
		a[i]=sum[i]-k*(i-1);
	}
	msort(1,n);
	cout<<ans;
}