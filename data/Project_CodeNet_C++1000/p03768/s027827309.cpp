#include<bits/stdc++.h>
using namespace std;
int n;
int m;
int mb[110000];
int dis[110000];
int v[110000];
int d[110000];
int c[110000];
struct KT
{
	int y;
	int next;
}f[210000];
int len;
int lin[210000];
void DJ(int xx,int yy)
{
	f[++len].next=lin[xx];
	f[len].y=yy;
	lin[xx]=len;
}
void KT(int x,int ys,int jl)
{
	if(!mb[x]) 
	mb[x]=ys;
	if(!jl||dis[x]>=jl) 
	return ;
	dis[x]=jl;
	for(int i=lin[x];i;i=f[i].next)
	{
		int y=f[i].y;
		KT(y,ys,jl-1) ;
	}
}
int q;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u;
		int v;
		cin>>u>>v;
		DJ(u,v);
		DJ(v,u);
	}
	cin>>q;
	for(int i=1;i<=q;i++) 
	{
		cin>>v[i]>>d[i]>>c[i];
	}
	
	for(int i=q;i>=1;i--) 
	{
		KT(v[i],c[i],d[i]);
	}
	for(int i=1;i<=n;i++) 
	{
		cout<<mb[i]<<endl;
	}
	return 0;
}