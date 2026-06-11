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
#define rrep(i, j, n) for(int i = (n) - 1; (j) <= i; --i)
constexpr i64 MOD = 1000000007;
constexpr i64 INF = 1LL << 60;


string s[55];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n, m; cin >> n >> m;

	vector<bool> aka(n, false);
	vector<int> cnt(n, 1);
	aka[0] = true;
	rep(i, 0, m) {
		int x, y; cin >> x >> y;
		--x, --y;
		if (aka[x]) {
			if (cnt[x] == 1) aka[x] = false;
			aka[y] = true;
		}
		cnt[x] -= 1;
		cnt[y] += 1;
	}

	int ans = 0;
	rep(i, 0, n) if (aka[i]) ++ans;
	cout << ans;
	return 0;
}