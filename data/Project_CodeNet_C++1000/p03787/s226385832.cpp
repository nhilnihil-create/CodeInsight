//Heaplax
//别让自己后悔
#include<bits/stdc++.h>
#define N 100001
#define M 400001
#define int long long
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
bool gg;
int ans,mark[N];
int n,m,cnt1,cnt2,cnt3,siz;
int cnt,head[N],nxt[M],to[M];
void dfs(int u)
{
	++siz;
	for(int i=head[u],v;i;i=nxt[i])
		if(!mark[v=to[i]])
		{
			mark[v]=-mark[u];
			dfs(v);
		}
		else if(mark[u]!=-mark[v])gg=1;
}
main()
{
	re(n),re(m);
	for(int i=1,u,v;i<=m;++i)
	{
		re(u),re(v);
		add_edge(u,v);
		add_edge(v,u);
	}
	for(int i=1;i<=n;++i)
		if(!mark[i])
		{
			siz=0;
			gg=0;
			mark[i]=1;
			dfs(i);
			if(siz==1)++cnt1;
			else if(gg)++cnt3;
			else ++cnt2;
		}
	ans=cnt1*(2*n-1)-cnt1*(cnt1-1)+cnt3*cnt3+2*cnt2*(cnt2+cnt3);
	printf("%lld\n",ans);
}
