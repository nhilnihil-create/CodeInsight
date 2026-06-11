
// Problem : D - Derangement
// Contest : AtCoder Regular Contest 082
// URL : https://atcoder.jp/contests/arc082/tasks/arc082_b
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define size(x) (int)x.size()

const int N = 1e6 + 1, mod = 1e9 + 7, inf = 2e9;

int n, ans = 0, p[N];

int main() { cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	for (int i = 1; i < n; i++) {
		if (p[i] == i) {
			swap(p[i], p[i + 1]);
			ans++;
		}
	}
	if (p[n] == n) ans++;
	cout << ans;
}
