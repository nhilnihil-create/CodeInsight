#include<bits/stdc++.h>
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
int n,x[MAX],m,d[MAX],ans[MAX],tmp[MAX];ll K;
double a[MAX];
int main()
{
	n=read();
	for(int i=1;i<=n;++i)x[i]=read();
	m=read();cin>>K;
	for(int i=1;i<=n;++i)d[i]=i,ans[i]=i;
	for(int i=1;i<=m;++i)
	{
		int x=read();
		swap(d[x],d[x+1]);
	}
	while(K)
	{
		if(K&1)
		{
			for(int i=1;i<=n;++i)tmp[i]=ans[d[i]];
			for(int i=1;i<=n;++i)ans[i]=tmp[i];
		}
		for(int i=1;i<=n;++i)tmp[i]=d[d[i]];
		for(int i=1;i<=n;++i)d[i]=tmp[i];
		K>>=1;
	}
	for(int i=1;i<=n;++i)a[i]=x[ans[i]]-x[ans[i]-1];
	for(int i=1;i<=n;++i)printf("%.1lf\n",a[i]+=a[i-1]);
	return 0;
}