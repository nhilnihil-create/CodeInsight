#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int N=1e5+10;
vector<int> son[N];
int n,k,ans,h[N];

int dfs(int u)
{
	bool flag=false;
	for(int i=0;i<son[u].size();++i)
	{
		int ht=dfs(son[u][i]);
		if(ht>=k-1) ++ans; else h[u]=max(h[u],ht),flag=true;
	};
	if(flag) ++h[u];
	return h[u];
}

int main()
{
	scanf("%d %d",&n,&k);
	int x;scanf("%d",&x);if(x!=1) ++ans;
	for(int i=2;i<=n;++i) scanf("%d",&x),son[x].push_back(i);
	for(int i=0;i<son[1].size();++i) dfs(son[1][i]);
	printf("%d\n",ans);
	return 0;
}