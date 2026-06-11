#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
int n, m, px, py;
bool vis[maxn + 10];
vector<int> ansl, ansr, g[maxn + 10];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int l, r; scanf("%d%d", &l, &r);
		g[l].push_back(r); g[r].push_back(l);
	}
	vis[px = py = 1] = 1;
	ansl.push_back(1);
	for (;;) {
		bool upd = 0;
		for (int i = 0; i < (int)g[px].size(); ++i) {
			int e = g[px][i];
			if (!vis[e]) {
				ansl.push_back(e); vis[e] = 1;
				px = e; upd = 1;
				break;
			}
		}
		if (upd) continue;
		for (int i = 0; i < (int)g[py].size(); ++i) {
			int e = g[py][i];
			if (!vis[e]) {
				ansr.push_back(e); vis[e] = 1;
				py = e; upd = 1;
				break;
			}
		}
		if (upd) continue;
		break;
	}
	printf("%d\n", (int)(ansl.size() + ansr.size()));
	for (int i = (int)ansl.size() - 1; i >= 0; --i) printf("%d ", ansl[i]);
	for (int i = 0; i < (int)ansr.size(); ++i) printf("%d ", ansr[i]);
}
