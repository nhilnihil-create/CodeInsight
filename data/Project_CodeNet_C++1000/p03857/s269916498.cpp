#include <bits/stdc++.h>
using namespace std;

struct dsu { // 0-indexed
	int n; // number of connected components
	vector<int> par;
	vector<int> sz;

	dsu(int _n) : n(_n), par(n, -1), sz(n, 1) { }

	int getpar(int a) {
		return par[a] == -1 ? a : (par[a] = getpar(par[a]));
	}

	bool merge(int a, int b) {
		a = getpar(a);
		b = getpar(b);
		if (a == b) return false;
		n--;
		if (sz[a] < sz[b]) swap(a, b);
		par[b] = a;
		sz[a] += sz[b];
		return true;
	}
};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int N, K, L; cin >> N >> K >> L;
	dsu roads(N);
	dsu railways(N);
	for (int k = 0; k < K; k++) {
		int a, b; cin >> a >> b; a--, b--;
		roads.merge(a, b);
	}
	for (int l = 0; l < L; l++) {
		int a, b; cin >> a >> b; a--, b--;
		railways.merge(a, b);
	}

	map<pair<int, int>, int> cnt;
	for (int i = 0; i < N; i++) {
		cnt[make_pair(roads.getpar(i), railways.getpar(i))]++;
	}

	for (int i = 0; i < N; i++) {
		cout << cnt[make_pair(roads.getpar(i), railways.getpar(i))] << " \n"[i == N - 1];
	}

	return 0;
}
