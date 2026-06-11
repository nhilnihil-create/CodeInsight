#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;

int n, m, a, b;
bool good, found_shit;
bool path[maxn];
vector < int > g[maxn];
deque < int > ans;

signed main () {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	path[1] = 1;
	ans.push_back(1);
	while (!good) {
		found_shit = 0;
		for (int v: g[ans.front()]) {
			if (!path[v]) {
				found_shit = 1;
				path[v] = 1;
				ans.push_front(v);
				break;
			}
		}
		if (found_shit)
			continue;
		for (int v: g[ans.back()]) {
			if (!path[v]) {
				found_shit = 1;
				path[v] = 1;
				ans.push_back(v);
				break;
			}
		}
		if (found_shit)
			continue;
		good = 1;
	}
	printf("%d\n", int(ans.size()));
	for (int i = 0; i < int(ans.size()); ++i)
		printf("%d ", ans[i]);
	printf("\n");
}
