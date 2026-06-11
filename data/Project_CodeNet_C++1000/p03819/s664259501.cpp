#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

const int N = 3e5;

struct Fenwick {
	int ft[N];
  int sum(int r) {
  	int result = 0;
  	for (; r >= 0; r = (r & (r + 1)) - 1)
  		result += ft[r];
  	return result;
  }
  int sum(int l, int r) {
      return (l > r ? 0ll : sum(r) - sum(l - 1));
  }
  void inc(int i, int delta) {
  	for (; i < N; i = (i | (i + 1)))
  		ft[i] += delta;
  }
} ft;

vector<pair<int, int> > add[N];
vector<int> querys[N];
int res[N];

void solve() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int l, r; cin >> l >> r;
		add[l].push_back({l, 1});
		add[r + 1].push_back({l, -1});
	}
	for (int d = 1; d <= m; d++) {
		for (int p = d; p <= m; p += d) {
			querys[p].push_back(d);
		}
	}
	for (int x = 1; x <= 2 * m; x++) {
		for (auto e : add[x]) {
			int left = e.first, delta = e.second;
			ft.inc(left, delta);
		}
		for (auto d : querys[x]) {
			int px = x - d;
			res[d] += ft.sum(px + 1, x);
		}
	}
	for (int d = 1; d <= m; d++) {
		cout << res[d] << "\n";
	}
}

// CHECK LIMITS (n <= 10^5)
// CHECK CORNER CASES (n == 1)

int main() {
  ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
  cout.setf(ios::fixed), cout.precision(20);
  //cout << 1.0 * clock() / CLOCKS_PER_SEC << endl;
  solve();
}
