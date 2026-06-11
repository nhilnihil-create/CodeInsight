#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
using namespace std;
using ll = long long;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)
#define rrep(i, j, n) for(int i = (n) - 1; (j) <= i; --i)

constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 60;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n, a, b; cin >> n >> a >> b;
	vector<double> v(n);
	rep(i, 0, n) cin >> v[i];
	sort(v.rbegin(), v.rend());

	double ans1 = 0.0;
	rep(i, 0, a) ans1 += v[i];
	ans1 /= (double)a;

	ll ans2 = 0;
	double target = v[a - 1];
	ll in = 0, all = 0;
	rep(i, 0, a) if (v[i] == v[a - 1]) ++in;
	rep(i, 0, n) if (v[i] == v[a - 1]) ++all;

	vector<vector<ll>> comb(55, vector<ll>(55, 0));
	rep(i, 1, 55) {
		comb[i][0] = 1;
		rep(j, 1, i) {
			comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
		}
		comb[i][i] = 1;
	}

	if (v[0] == v[a - 1]) {
		rep(i, a, b + 1) {
			ll need = a - in;
			ll free = i - need;
			ans2 += comb[all][free];
		}
	}
	else {
		ans2 = comb[all][in];
	}

	cout << fixed << setprecision(10) << ans1 << " " << ans2 << endl;

	return 0;
}