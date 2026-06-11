#include<algorithm>
#include<iostream>
#include<cstdio>
#define MN 100000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,a[MN+5],p[MN+5],vis[MN+5],q[MN+5],top,b[MN+5];
long long K;
int main()
{
	n=read();
	for(int i=1;i<=n;++i) p[i]=read();
	for(int i=1;i<n;++i) a[i]=i;
	m=read();cin>>K;
	for(int i=1;i<=m;++i)
	{
		int x=read();
		swap(a[x-1],a[x]);	
	}
	for(int i=1;i<n;++i) if(!vis[i])
	{
		vis[q[top=1]=i]=1;
		for(int x=a[i];!vis[x];x=a[x]) vis[q[++top]=x]=1;
		int add=top-K%top;
		for(int j=1;j<=top;++j) b[q[(j+add-1)%top+1]]=p[q[j]+1]-p[q[j]];
	}
	long long s=p[1];
	for(int i=1;i<=n;++i) printf("%lld\n",s),s+=b[i];
	return 0;
}

