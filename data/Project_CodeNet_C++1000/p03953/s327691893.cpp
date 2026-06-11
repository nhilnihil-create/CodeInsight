#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

const int N=1e5+10;

bool vis[N];
int n,m,cnt,pos[N],a[N],node[N],to[N];
LL ans[N];
LL k;

void Init()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d",&pos[i]);
	scanf("%d%lld",&m,&k);
	for (int i=1;i<=m;++i) scanf("%d",&a[i]);
}

void Dfs(int x)
{
	if (vis[x]) return ;
	vis[x]=1;
	node[cnt++]=x;
	Dfs(to[x]);
	
}

void Solve()
{
	for (int i=n;i>=2;--i) pos[i]-=pos[i-1];
	for (int i=1;i<=n;++i) to[i]=i;
	for (int i=1;i<=m;++i) swap(to[a[i]],to[a[i]+1]);
	
	for (int i=1;i<=n;++i)
		if (!vis[i])
		{
			cnt=0;
			Dfs(i);
			for (int j=0;j<cnt;++j)
				ans[node[j]]=pos[node[(j+k)%cnt]];
		}
	
	for (int i=2;i<=n;++i) ans[i]+=ans[i-1];
	
	for (int i=1;i<=n;++i) printf("%lld.0\n",ans[i]);
}

int main()
{
	Init();
	Solve();
	return 0;
}
