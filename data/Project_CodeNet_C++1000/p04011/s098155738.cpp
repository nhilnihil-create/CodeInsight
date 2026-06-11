#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9 + 7;
const int N = 1e6 + 5;

int main() {
	int n, k, x, y;
	long long ans = 0;
	cin >> n >> k >> x >> y;
	ans = min(n, k) * x;
	n -= min(n, k);
	ans += n * y;
	cout << ans << endl;
	return 0;
}