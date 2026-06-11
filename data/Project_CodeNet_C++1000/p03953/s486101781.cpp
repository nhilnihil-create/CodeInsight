#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 10;
int mark[N], nxt[N], x[N], a[N], n, m, ans[N];
long long k;
vector<int> tps;
void dfs(int v) {
	mark[v] = 1, tps.push_back(v);
	if (!mark[nxt[v]])
		dfs(nxt[v]);
}
int main() {
	ios_base::sync_with_stdio (false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n - 1; i++)
		x[i] = a[i + 1] - a[i];
	iota(nxt, nxt + n + 1, 0);
	cin >> m >> k;
	for (int i = 0; i < m; i++) {
		int y;
		cin >> y;
		y--;
		swap(nxt[y], nxt[y - 1]);
	}
	for (int i = 0; i < n; i++) {
		if (!mark[i]) {
			dfs(i);
			int fw = k % ((long long) tps.size());
			for (int i = 0; i < tps.size(); i++)
				ans[tps[i]] = x[tps[(i + fw) % tps.size()]];
			tps.clear();
		}
	}
	long long lst = a[0];
	cout << a[0] << "\n";
	for (int i = 0; i < n - 1; i++) {
		lst = lst + ans[i];
		cout << lst << "\n";
	}

	return 0;	
}
