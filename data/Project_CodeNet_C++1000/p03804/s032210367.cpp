#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <unordered_map>
#include <iomanip>
#include <cmath>
#include <tuple>
using namespace std;
using ll = long long;
#define rep(i, j, n) for(int i = j; i < (int)n; ++i)
#define rrep(i, j, n) for(int i = (int)n - 1; j <= i; --i)

constexpr ll MOD = 0x3b9aca07;
constexpr int INF = 0x3f3f3f3f;
constexpr ll INFL = 0x3f3f3f3f3f3f3f3fLL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n, m; cin >> n >> m;

	vector<string> a(n), b(m);
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, m) cin >> b[i];

	rep(i, 0, n) {
		rep(j, 0, n) {
			bool ok = true;
			rep(k, 0, m) {
				rep(l, 0, m) {
					if (i + k >= n || j + l >= n || a[i + k][j + l] != b[k][l]) ok = false;
				}
			}
			if (ok)
			{
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;

	return 0;
}
