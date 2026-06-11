#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int nm = 1e5;
int n, m, q, x[11][nm], v[nm], d[nm], c[nm];
vector<int> g[nm];

void f(int v, int d, int c) {
	if (x[d][v] > 0)
		return;
	x[d][v] = c;
	if (!d)
		return;
	f(v, d - 1, c);
	for (int nv : g[v])
		f(nv, d - 1, c);
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	cin >> q;
	for (int i = 0; i < q; ++i)
		cin >> v[i] >> d[i] >> c[i];
	for (int i = q - 1; i >= 0; --i)
		f(v[i] - 1, d[i], c[i]);
	for (int i = 0; i < n; ++i)
		cout << x[0][i] << endl;

}
