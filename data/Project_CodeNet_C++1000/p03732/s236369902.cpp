#include <bits/stdc++.h>
using namespace std;

int n, wmax, ans, minw;
vector<int> g[4];
int cap[4];

void solve (int k) {
	if (k == 4) {

		long long total = 0;
		for (int i = 0; i < 4; i++)
			total += (long long)cap[i] * (minw + i);
		if (total > wmax) return;

		int tmp = 0;
		for (int i = 0; i < 4; i++)
			tmp += (cap[i] ? g[i][cap[i] - 1] : 0);
		cerr << tmp << '\n';
		ans = max(ans, tmp);
		return;
	}

	for (int i = 0; i <= (int)g[k].size(); i++) {
		cap[k] = i;
		solve(k + 1);
	}
}

int main() {
	scanf("%d%d", &n, &wmax);
	int w, x;
	scanf("%d%d", &minw, &x);
	g[0].push_back(x);
	
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &w, &x);
		g[w - minw].push_back(x);
	}

	for (int i = 0; i < 4; i++) {
		sort(g[i].begin(), g[i].end());
		reverse(g[i].begin(), g[i].end());
		for (int j = 1; j < (int)g[i].size(); j++)
			g[i][j] += g[i][j - 1];
	}

	ans = 0;	
	solve(0);
	printf("%d\n", ans);
}

