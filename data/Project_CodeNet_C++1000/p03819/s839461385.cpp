#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

int bit[N], f[N], ans[N];

vector <pair <int, int> > Q[N];

void update(int idx, int value) {
	for(int i = idx; i < N; i += i & -i) {
		bit[i] += value;
	}
}

int query(int idx) {
	int res = 0;
	for(int i = idx; i > 0; i -= i & -i) {
		res += bit[i];
	}
	return res;
}

int main() {
	ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		int l, r; cin >> l >> r;
		f[r - l]++;
		Q[r - l].push_back(make_pair(l, r));
	}

	for(int i = N - 2; i >= 0; i--) {
		f[i] += f[i + 1];
	}

	for(int i = 1; i <= m; i++) {
		if(i - 2 >= 0) {
			for(auto z: Q[i - 2]) {
				int l, r; tie(l, r) = z;
				update(l, +1);
				update(r + 1, -1);
			}
		}
		ans[i] += f[i - 1];
		for(int j = i; j <= m; j += i) {
			ans[i] += query(j);
		}
		cout << ans[i] << "\n";
	}
}