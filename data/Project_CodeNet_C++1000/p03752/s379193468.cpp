#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORR(i, a, b) for (int i = b - 1; i >= a; --i)
#define SORT(v) sort(v.begin(), v.end())
#define SORTR(v) sort(v.rbegin(), v.rend())
#define REV(v) reverse(v.begin(), v.end())
#define ITER(itr, v) for (auto itr = v.begin(); itr != v.end(); ++itr)
#define LB(v, x) (lower_bound(v.begin(), v.end(), x) - v.begin())
#define UB(v, x) (upper_bound(v.begin(), v.end(), x) - v.begin())
#define SZ(v) (int)v.size()
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;
	vector<ll> a(N);
	REP(i, N) { cin >> a[i]; }
	ll res = INT64_MAX;
	for (int bit = 0; bit < (1 << N); ++bit) {
		vector<int> choice(N);
		int cnt = 0;
		REP(i, N) {
			if (bit >> i & 1) {
				choice[i] = 1;
				++cnt;
			}
		}
		if (cnt != K) continue;

		ll sum = 0;
		ll mx = 0;
		REP(i, N) {
			if (a[i] > mx) {
				mx = a[i];
			} else if (choice[i]) {
				++mx;
				sum += mx - a[i];
			}
		}
		res = min(res, sum);
	}
	cout << res << endl;

	return 0;
}
