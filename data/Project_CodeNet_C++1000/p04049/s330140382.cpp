#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define P pair<int,int>
const LL inf = 0x3f3f3f3f;
const LL mod = 1e9+7;
const LL N = 2e3+10;
template <typename tp> inline void read(tp &x)
{
	x=0;char c=getchar();int f=0;
	for(;c>'9'||c<'0';f|=(c=='-'),c=getchar());
	for(;c<='9'&&c>='0';x=(x<<3)+(x<<1)+c-'0',c=getchar());
	if(f) x=-x;
}
int n,k,ans=inf;
struct Edge{int next,to;}edge[N*2];
P e[N];
int head[N],cnt;
void add(int from,int to)
{
	edge[++cnt].next=head[from];
	edge[cnt].to=to;
	head[from]=cnt;
}
int dfs(int now,int fa,int dp,int ret=1)
{
	if(!dp) return 0;
	for(int i=head[now];i;i=edge[i].next)
	{
		int to=edge[i].to;
		if(to==fa) continue;
		ret+=dfs(to,now,dp-1);
	}
	return ret;
}
signed main()
{
	read(n),read(k);
	for(int i=1;i<n;i++) read(e[i].first),read(e[i].second),add(e[i].first,e[i].second),add(e[i].second,e[i].first);
	if(k%2==0) for(int i=1;i<=n;i++) ans=min(ans,n-dfs(i,i,k/2+1));
	else for(int i=1;i<n;i++) ans=min(ans,n-dfs(e[i].first,e[i].second,k/2+1)-dfs(e[i].second,e[i].first,k/2+1));
	printf("%d\n",ans);
	return 0;
}