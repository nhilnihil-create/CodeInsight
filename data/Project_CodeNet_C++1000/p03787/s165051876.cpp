#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

vector <int> ad[N];
long long n, m;
int mrk[N];

bool dfs(int v) {
	bool ok = 0;
	for (auto u: ad[v]) {
		if (mrk[v] == mrk[u])
			ok = 1;
		if (!mrk[u]) { 
			mrk[u] = 3 - mrk[v];
			ok |= dfs(u);
		}
	}
	return ok;
}

int main() {
	cin >> n >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		ad[x].push_back(y);
		ad[y].push_back(x);
	}
	long long k = 0, g = 0, one = 0;
	for (int i = 1; i <= n; i++)
		if (!mrk[i]) {
			mrk[i] = 1;
			if (dfs(i))
				g++;
			else
				k++;
			if (ad[i].size() == 0)
				one++, k--;
		}
	cout << 2 * k * k + 2 * k * g + g * g + 2 * one * (n) - one * one;
	return 0;
}

























