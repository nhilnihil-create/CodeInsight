#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)
constexpr ll INF = 1LL << 60;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);
	ll n, x; cin >> n >> x;
	vector<ll> a(n);
	rep(i, 0, n) cin >> a[i];


	vector<ll> min_table(n, INF);
	ll ans = INF;
	rep(i, 0, n) {
		rep(j, 0, n) min_table[j] = min(min_table[j], a[(n + j - i) % n]);
		ll tans = x * i;
		rep(j, 0, n)
			tans += min_table[j];

		ans = min(ans, tans);
	}
	cout << ans << endl;
	return 0;
}