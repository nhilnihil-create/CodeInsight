#include <bits/stdc++.h>
using namespace std;
#define repl(i, l, r) for (ll i = (l); i < (r); i++)
#define rep(i, n) repl(i, 0, n)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define CST(x) cout << fixed << setprecision(x)
using ll = long long;
const ll MOD = 1000000007;
const int inf = 1e9 + 10;
const ll INF = 4e18 + 10;
const int dx[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
const int dy[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	vector<int> a(9);
	int n;
	cin >> n;
	rep(i, n) {
		int p;
		cin >> p;
		if (p < 3200)
			a[p / 400]++;
		else
			a[8]++;
	}
	int P = 0;
	rep(i, 8) if (a[i]) P++;
	if (P) {
		cout << P << " " << P + a[8] << endl;
	} else {
		cout << 1 << " " << a[8] << endl;
	}
	return 0;
}