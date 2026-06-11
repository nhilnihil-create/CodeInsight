#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<unordered_map>
int par_road[200001], par_rail[200001], num[200000];
std::pair<std::pair<int, int>,int> roots[200000];
int root(int* par, int x) {
	return par[x] == x ? x : par[x] = root(par, par[x]);
}
void unite(int* par, int x, int y) {
	int xp = root(par, x), yp = root(par, y);
	if (xp != yp)par[xp] = yp;
}
int main() {
	int n, k, l, i, j, a, b;
	scanf("%d%d%d", &n, &k, &l);
	for (i = 1; i <= n; i++) {
		par_road[i] = i;
		par_rail[i] = i;
	}
	for (i = 1; i <= k; i++) {
		scanf("%d%d", &a, &b);
		unite(par_road, a, b);
	}
	for (i = 1; i <= l; i++) {
		scanf("%d%d", &a, &b);
		unite(par_rail, a, b);
	}
	for (i = 1; i <= n; i++) {
		par_road[i] = root(par_road, i);
		par_rail[i] = root(par_rail, i);
		roots[i] = { {par_road[i],par_rail[i]},i };
	}
	std::sort(roots + 1, roots + n + 1);
	for (i = 1; i <= n; i = j) {
		for (j = i+1; j <= n; j++) {
			if (roots[j].first != roots[i].first)break;
		}
		for (k = i; k < j; k++)num[roots[k].second] = j - i;
	}
	for (i = 1; i <= n; i++)printf("%d%s", num[i], i == n ? "\n" : " ");
	return 0;
}