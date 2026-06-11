#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> gr[N];
int slt, cnt[5], mark[N];
long long ans;
bool z;
void dfs(int v, int rang = 1) {
	mark[v] = rang;
	for (auto u : gr[v]) {
		if (!mark[u])
			dfs(u, 3 - rang);
		else {
			if (mark[u] == mark[v])
				z = true;
		}
	}	
}
int main() {
	int n, m;
	cin >> n >> m;
	slt = n;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
	for (int i = 0; i < n; i++) {
		z = false;
		if (!mark[i]) {
			if (gr[i].size() > 0) {
				dfs(i);
				if (z == true)
					cnt[0]++;
				else
					cnt[1]++;
			}
			else {
				slt--;
			}
		}
	}
	ans = 1ll * n * n - 1ll * slt * slt + cnt[0] + 2 * cnt[1] + 1ll * cnt[0] * (cnt[0] - 1) + 1ll * 2 * cnt[1] * cnt[0] + 1ll * 2 * cnt[1] * (cnt[1] - 1);
	cout << ans;
	return 0;
}
