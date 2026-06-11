//Heaplax
//别让自己后悔
#include<bits/stdc++.h>
#define N 100001
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
int n,a[N],f[N];
int cnt,head[N],nxt[N],to[N];
void dfs(int u)
{
	vector<int> que;
	for(int i=head[u],v;i;i=nxt[i])
		dfs(v=to[i]),que.push_back(f[v]);
	sort(que.begin(),que.end(),greater<int>());
	for(int i=0;i<que.size();++i)
		f[u]=max(f[u],i+1+que[i]);
}
int main()
{
	re(n);
	for(int i=2;i<=n;++i)
		re(a[i]),add_edge(a[i],i);
	dfs(1);
	printf("%d\n",f[1]);
}
