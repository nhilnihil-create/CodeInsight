#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
#define MAX 100100
inline int read()
{
	int x=0;bool t=false;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')t=true,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	return t?-x:x;
}
int n,m;
int a[MAX<<1],b[MAX<<1];
bool check(int mid)
{
	for(int i=1;i<=m;++i)b[i]=a[i]>=mid;
	for(int i=0;i<n;++i)
	{
		if(b[n-i]==b[n-i-1])return b[n-i];
		if(b[n+i]==b[n+i+1])return b[n+i];
	}
	return b[1];
}
int main()
{
	n=read();m=n+n-1;
	for(int i=1;i<=m;++i)a[i]=read();
	int l=1,r=m,ret;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))ret=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",ret);
	return 0;
}
