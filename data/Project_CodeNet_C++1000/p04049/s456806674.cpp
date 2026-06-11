#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int n,k,mi,gs,x[N],y[N];
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
void dfs(int u,int fa,int dep)
{
	if(dep>k/2)gs++;
	for(int i=0;i<g[u].size();i++)
	{
		int v=g[u][i];
		if(v==fa)continue;
		dfs(v,u,dep+1);
	}
}
int main()
{
	n=read();k=read();
	mi=n;
	for(int i=1;i<n;i++)
	{
		x[i]=read(),y[i]=read();
		g[x[i]].push_back(y[i]);
		g[y[i]].push_back(x[i]);
	}
	if(k%2==0)
	{
		for(int i=1;i<=n;i++)
		{
			gs=0;
			dfs(i,0,0);
			mi=min(mi,gs);
		}
		cout<<mi;
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		gs=0;
		dfs(x[i],y[i],0);
		dfs(y[i],x[i],0);
		mi=min(mi,gs);
	}
	cout<<mi;
	return 0;
}