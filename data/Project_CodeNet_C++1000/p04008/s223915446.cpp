#include <cstdio>
#include <algorithm>
const int maxn = 1e5 + 5;
using namespace std;
struct E{
	int to, nxt;
}e[maxn];
int head[maxn], tot = 0;
void addedge(int u, int v){
	e[++tot].to = v, e[tot].nxt = head[u];
	head[u] = tot;
}
int a[maxn], dep[maxn], n, k, ans = 0;
void dfs(int cur, int fa){
	for (int i = head[cur]; i; i = e[i].nxt){
		int v = e[i].to;
		dfs(v, cur);
		dep[cur] = max(dep[cur], dep[v] + 1);
	}
	if (fa != 1 && dep[cur] == k - 1 && cur != 1) dep[cur] = -1, ++ans;
}
int main(){
	scanf("%d%d%d", &n, &k, a + 1);
	if (a[1] != 1) a[1] = 1, ++ans;
	for (int i = 2; i <= n; i++){
		scanf("%d", a + i);
		addedge(a[i], i);
	}
	dfs(1, 0);
	printf("%d\n", ans);
	return 0;
}
