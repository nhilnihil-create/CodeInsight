#include <bits/stdc++.h>
#define cina(a, n) for (int i = 0; i < n; ++i){ cin >> a[i]; }
#define ll long long
#define ld long double

using namespace std;

int main () {
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	ll n, k, x, y, cost = 0;
	cin >> n >> k >> x >> y;
	cost += min(n, k) * x;
	n -= min(n, k);
	if (n) {
		cost += n * y;
	}
	cout << cost;
	return 0;
}