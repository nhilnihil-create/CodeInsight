#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<algorithm>

#define maxn 200005

using namespace std;

inline int getint()
{
	int num=0,flag=1;char c;
	while((c=getchar())<'0'||c>'9')if(c=='-')flag=-1;
	while(c>='0'&&c<='9')num=num*10+c-48,c=getchar();
	return num*flag;
}

map<long long,int>sz;
int n,k,l;
int fir[maxn],nxt[maxn],to[maxn],cnt;
int f1[maxn];
int f2[maxn];

inline void newnode(int u,int v)
{to[++cnt]=v,nxt[cnt]=fir[u],fir[u]=cnt;}

void dfs1(int u)
{
	for(int i=fir[u];i;i=nxt[i])
		if(!f1[to[i]])
		{
			f1[to[i]]=f1[u];
			dfs1(to[i]);
		}
}

void dfs2(int u)
{
	for(int i=fir[u];i;i=nxt[i])
		if(!f2[to[i]])
		{
			f2[to[i]]=f2[u];
			dfs2(to[i]);
		}
}


int main()
{
	n=getint(),k=getint(),l=getint();
	for(int i=1;i<=k;i++)
	{
		int a=getint(),b=getint();
		newnode(a,b),newnode(b,a);
	}
	for(int i=1;i<=n;i++)
		if(!f1[i])f1[i]=i,dfs1(i);
	memset(fir,0,sizeof fir);memset(nxt,0,sizeof nxt);
	memset(to,0,sizeof to);cnt=0;
	for(int i=1;i<=l;i++)
	{
		int a=getint(),b=getint();
		newnode(a,b),newnode(b,a);
	}
	for(int i=1;i<=n;i++)
		if(!f2[i])f2[i]=i,dfs2(i);
	for(int i=1;i<=n;i++)
		sz[(long long)f1[i]*maxn+f2[i]]++;
	for(int i=1;i<=n;i++)
		if(i==n)printf("%d\n",sz[(long long)f1[i]*maxn+f2[i]]);
		else printf("%d ",sz[(long long)f1[i]*maxn+f2[i]]);
}