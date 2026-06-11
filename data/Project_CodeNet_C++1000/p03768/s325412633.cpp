#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,q,a[N],b[N],c[N],mx[N],col[N];
vector<int>g[N];
/*char buf[1<<21],*p1=buf,*p2=buf;
inline int gc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}*/
#define gc getchar
inline int read()
{
    int ret=0,f=0;char c=gc();
    while(!isdigit(c)){if(c=='-')f=1;c=gc();}
    while(isdigit(c)){ret=ret*10+c-48;c=gc();}
    if(f)return -ret;return ret;
}
void dfs(int x,int y,int z)
{
	if(mx[x]>=y)return;
	mx[x]=y;
	if(!col[x])col[x]=z;
	if(y==0)return;
	for(int i=0;i<g[x].size();i++)
	{
		int v=g[x][i];
		dfs(v,y-1,z);
	}
}
int main()
{
	memset(mx,-1,sizeof(mx));
	n=read();m=read();
	for(int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		g[x].push_back(y);
		g[y].push_back(x);
	}
	q=read();
	for(int i=1;i<=q;i++)
	{
		a[i]=read();b[i]=read();c[i]=read();
	}
	for(int i=q;i;i--)
		dfs(a[i],b[i],c[i]);
	for(int i=1;i<=n;i++)printf("%d\n",col[i]);
}