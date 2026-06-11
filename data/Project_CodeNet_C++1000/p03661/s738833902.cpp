
// Problem : C - Splitting Pile
// Contest : AtCoder Regular Contest 078
// URL : https://atcoder.jp/contests/arc078/tasks/arc078_a
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define size(x) (int)x.size()

const int N = 1e6 + 1, mod = 1e9 + 7, inf = 2e9;

int n;
ll ans = LLONG_MAX, sum[N];

int main() { cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 1, x; i <= n; i++) {
		cin >> x;
		sum[i] = sum[i - 1] + x;
	}
	for (int i = 1; i < n; i++) {
		ans = min(ans, abs(2 * sum[i] - sum[n]));
	}
	cout << ans;
}
