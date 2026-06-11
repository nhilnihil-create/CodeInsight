#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <cmath>
#include <queue>
using namespace std;
using i64 = int64_t;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)
#define rrep(i, j, n) for(int i = (n - 1); (j) <= i; --i)
constexpr i64 MOD = 1000000007;
constexpr i64 INF = 1LL << 60;

bool x[200000], y[200000];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n, m, a, b; cin >> n >> m;
	rep(i, 0, m) {
		cin >> a >> b;
		--a, --b;
		if (a > b) swap(a, b);
		if (a == 0) x[b] = true;
		if (b == n - 1) y[a] = true;
	}
	rep(i, 1, n - 1) {
		if (x[i] && y[i]) {
			cout << "POSSIBLE";
			return 0;
		}
	}
	cout << "IMPOSSIBLE";
	return 0;
}