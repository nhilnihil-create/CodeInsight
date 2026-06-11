#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int n, m, a[N], go[N], bg[N], ps[N];
ll k, chaf[N], ans[N], x[N];
bool vis[N];
vector<int> cir[N];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%lld", &x[i]);
	for (int i = 1; i <= n; ++i) chaf[i] = x[i] - x[i - 1];
	scanf("%d%lld", &m, &k);
	for (int i = 1; i <= m; ++i) scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i) go[i] = i;
	for (int i = 1; i <= m; ++i) swap(go[a[i]], go[a[i] + 1]);
	for (int i = 1; i <= n; ++i) {
		if (vis[i]) continue ;
		int u = i;
		while (!vis[u]) {
			vis[u] = 1;
			bg[u] = i;
			u = go[u];
		}
		u = i;
		bg[u] = i;
		cir[i].push_back(u);
		ps[u] = 0;
		while (go[u] != i) {
			u = go[u];
			ps[u] = cir[i].size();
			cir[i].push_back(u);
		}
	}
	for (int i = 1; i <= n; ++i) ans[i] = chaf[cir[bg[i]][(ps[i] + k) % cir[bg[i]].size()]];
	for (int i = 1; i <= n; ++i) ans[i] += ans[i - 1];
	for (int i = 1; i <= n; ++i) printf("%lld\n", ans[i]);
	return 0;
}