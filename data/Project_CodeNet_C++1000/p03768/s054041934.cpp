//Heaplax
//别让自己后悔
#include<bits/stdc++.h>
#define N 100001
#define M 200001
#define LL long long
#define LOG(x) cerr<<#x<<" = "<<x<<endl
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
char ch;bool fs;void re(int& x)
{
	while(ch=getchar(),ch<33);
	if(ch=='-')fs=1,x=0;else fs=0,x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
	if(fs)x=-x;
}
using namespace std;
int col[N],md[N];
int n,m,q,vv[N],dd[N],cc[N];
int cnt,head[N],nxt[M],to[M];
void color(int u,int fa,int d,int c)
{
	if(!col[u])col[u]=c;
	if(d<=md[u])return;
	md[u]=max(md[u],d);
	for(int i=head[u],v;i;i=nxt[i])
		if((v=to[i])!=fa)
			color(v,u,d-1,c);
}
int main()
{
	re(n),re(m);
	for(int i=1,u,v;i<=m;++i)
	{
		re(u),re(v);
		add_edge(u,v);
		add_edge(v,u);
	}
	re(q);
	for(int i=1;i<=q;++i)
		re(vv[i]),re(dd[i]),re(cc[i]);
	for(int i=q;i;--i)
		color(vv[i],0,dd[i],cc[i]);
	for(int i=1;i<=n;++i)
		printf("%d\n",col[i]);
}
