#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 100;

ll n, k, ans, ps[N], good[N];

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		ps[i] = ps[i - 1] + a;
		good[i] = good[i - 1] + max(0, a);
	}
	for (int i = k; i <= n; i++)
		ans = max(ans, max(0LL, ps[i] - ps[i - k]) + good[i - k] + good[n] - good[i]);
	cout << ans;
}
