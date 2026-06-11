#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

const int N=100005;

int n,m,a[N];
LL b[N];

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int main()
{
	n=read();m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	LL ans=0;
	for (int i=1;i<n;i++)
	{
		int l=a[i]+1,r=a[i+1],s;
		if (l<=r) b[l+1]++,b[r+1]-=r-l+1,b[r+2]+=r-l,ans+=r-l+1;
		else b[l+1]++,s=m-l+1,b[1]+=s,b[2]-=s-1,b[r+1]-=s+r,b[r+2]+=s+r-1,ans+=m-l+r+1;
	}
	for (int i=1;i<=m;i++) b[i]+=b[i-1];
	for (int i=1;i<=m;i++) b[i]+=b[i-1];
	LL mx=0;
	for (int i=1;i<=m;i++) mx=max(mx,b[i]);
	cout<<ans-mx;
	return 0;
}