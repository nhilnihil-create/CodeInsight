#include<bits/stdc++.h>
 using namespace std;
#define LL long long
#define P pair<LL,LL>
 const LL inf = 0x3f3f3f3f;
 const LL mod = 1e9+7;
 const LL N = 1e5+10;
 template <typename tp> inline void read(tp &x)
{
		x=0;char c=getchar();int f=0;
			for(;c>'9'||c<'0';f|=(c=='-'),c=getchar());
				for(;c<='9'&&c>='0';x=(x<<3)+(x<<1)+c-'0',c=getchar());
					if(f) x=-x;
}
int n,k,head[N],cnt,ans;
struct Edge{int next,to;} edge[N*2];
void add(int from,int to)
{
	edge[++cnt].next=head[from];
	edge[cnt].to=to;
	head[from]=cnt;
}
int dfs(int now,int fa)
{
	int flag=0;
	for(int i=head[now];i;i=edge[i].next)
	{
		int to=edge[i].to;
		if(to==fa||to==now) continue;
		int zz=dfs(to,now)+1;
		if(zz==k&&now!=1) ans++,zz=0;
		flag=max(zz,flag);
	}
	if(now==1) return 0;
	if(flag==k) ans++,flag=0;
	return flag;
}
signed main()
{
	read(n),read(k);
	for(int i=1,v;i<=n;i++)
	{
		read(v);
		if(i==1) 
		{
			if(v!=1) ans++;
			continue;
		}
		add(i,v),add(v,i);
	}
	dfs(1,1);
	printf("%d\n",ans);
	return 0;
}