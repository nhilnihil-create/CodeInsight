#include <bits/stdc++.h>
using namespace std;

const int N = 300001;
int n, m, tot = 0, q;
int head[N], Next[N], ver[N], num[N];
int ans[N][20] = {};
struct edge{
	int x, y, z;
}a[N];

vector <int> vis[N];

void dfs(int x,int y,int z) {
	if (y == -1) return;
	if (ans[x][y]) return;
	ans[x][y] = z;
	for (int i=0;i<vis[x].size();++i) dfs(vis[x][i], y-1, z);
}

int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) {
		int x, y;
		scanf("%d%d",&x,&y);
		vis[x].push_back(y);
		vis[y].push_back(x);
	}
	for (int i=1;i<=n;i++) vis[i].push_back(i);
	scanf("%d",&q);
	for (int i=1;i<=q;i++) {
		int x, y, z;
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
	}
	for (int i=q;i;--i) dfs(a[i].x, a[i].y, a[i].z);
	for (int i=1;i<=n;i++) printf("%d\n",ans[i][0]);
	return 0;
}