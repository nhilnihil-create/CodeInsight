#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iomanip>
#include <cmath>
using namespace std;
using ll = long long;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)
#define rrep(i, j, n) for(int i = (n) - 1; (j) <= i; --i)
constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 60;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);


	int k, s; cin >> k >> s;
	int ans = 0;
	rep(i, 0, k + 1) {
		rep(j, 0, k + 1) {
			int sum = s - i - j;
			if (0 <= sum && sum <= k) ++ans;
		}
	}
	cout << ans << endl;
	return 0;
}