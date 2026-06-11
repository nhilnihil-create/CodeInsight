#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using i64 = int64_t;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)
constexpr i64 INF = 1LL << 60;

int main() {
	i64 n, x; cin >> n >> x;
	i64* a = new i64[n];
	rep(i, 0, n) cin >> a[i];

	vector<vector<i64>> mind(n + 1, vector<i64>(n, INF));
	rep(i, 0, n) mind[0][i] = a[i];

	i64 ans = INF;
	rep(i, 0, n) {
		i64 cnt = x * i;
		rep(j, 0, n)
			cnt += mind[i][j];
		ans = min(ans, cnt);

		// update table
		rep(j, 0, n)
			mind[i + 1][j] = min(mind[i][j], a[(n + j - i - 1) % n]);
	}
	cout << ans << endl;
	delete[] a;
	return 0;
}