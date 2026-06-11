#include <bits/stdc++.h>
using namespace std;

struct DSU{
	vector <int> p, sz;
	DSU(int n) {
		p.resize(n + 1); sz.resize(n + 1, 1);
		for(int i = 1; i <= n; i++) {
			p[i] = i;
		}
	}
	int find(int x) {
		return p[x] = (p[x] == x) ? p[x] : find(p[x]);
	}
	int merge(int x, int y) {
		x = find(x);
		y = find(y);
		if(x == y) {
			return 0;
		}
		p[x] = y;
		sz[y] += sz[x];
		return 1;
	}
};

const int N = 2e5 + 7;

vector <int> lst[N];

int ans[N];

int main() {
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k, l; cin >> n >> k >> l; DSU a(n), b(n);
	for(int i = 1; i <= k; i++) {
		int x, y; cin >> x >> y;
		a.merge(x, y);
	}
	for(int i = 1; i <= l; i++) {
		int x, y; cin >> x >> y;
		b.merge(x, y);
	}

	for(int i = 1; i <= n; i++) {
		lst[a.find(i)].push_back(i);
	}

	for(int i = 1; i <= n; i++) {
		vector <int> t;
		for(int x: lst[i]) {
			t.push_back(b.find(x));
		}
		sort(t.begin(), t.end());
		for(int x: lst[i]) {
			ans[x] = upper_bound(t.begin(), t.end(), b.find(x)) - lower_bound(t.begin(), t.end(), b.find(x));
		}
	}
	for(int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
}