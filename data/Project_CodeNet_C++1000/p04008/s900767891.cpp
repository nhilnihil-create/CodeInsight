#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100100;
struct Edge {
	int to;
	Edge *next;
}*h[N], e[N<<2];
int _;
int ans = 0, n, k, a[N];
int dep[N];
void add_edge(int u, int v) {
	Edge *tmp = &e[++_];
	tmp -> to = v;
	tmp -> next = h[u];
	h[u] = tmp;
}
void dfs(int p) {
	dep[p] = 1;
	for(Edge *i = h[p]; i; i=i->next) {
		dfs(i->to);
		dep[p] = max(dep[p], dep[i->to]+1);
	}
	if(dep[p] >= k && a[p] > 1) {
		dep[p] = 0; 
		ans ++;
	}
}
int main() {
	scanf("%d%d",&n ,&k);
	for(int i = 1; i <= n; i ++ ) {
		scanf("%d", &a[i]);
	}
	if(a[1]!=1) ans ++, a[1] = 1;
	for(int i = 2; i <= n; i ++ ) add_edge(a[i], i);
	dfs(1);
	printf("%d\n", ans);
}
