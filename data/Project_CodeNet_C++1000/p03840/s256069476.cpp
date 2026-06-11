#include <bits/stdc++.h>
using namespace std;

const int N = 10;
int a[N]; long long ans, tmp;
int main () {
	for (int i = 1; i <= 7; ++i) cin >> a[i];
	ans = 1ll * a[2] + a[1] / 2 * 2 + a[4] / 2 * 2 + a[5] / 2 * 2;
	if ((a[1] & 1) && (a[4] & 1) && (a[5] & 1)) ans += 3;
	tmp = 1ll * a[2] + (a[1] - 1) / 2 * 2 + (a[4] - 1) / 2 * 2 + (a[5] - 1) / 2 * 2 + 3;
	if (a[1] && a[4] && a[5]) ans = max(ans, tmp);
	cout << ans << endl;
	return 0;
}