#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)
#define rrep(i, j, n) for(int i = (n) - 1; (j) <= i; --i)
constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 60;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);
	int h, w, n; cin >> w >> h >> n;

	int l = 0, r = w;
	int d = 0, u = h;
	rep(i, 0, n) {
		int x, y, a;
		cin >> x >> y >> a;
		if (a == 1) l = max(l, x);
		if (a == 2) r = min(r, x);
		if (a == 3) d = max(d, y);
		if (a == 4) u = min(u, y);
	}
	cout << max(0, r - l) * max(0, u - d) << endl;
	return 0;
}
