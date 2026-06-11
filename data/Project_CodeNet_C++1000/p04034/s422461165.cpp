#include<bits/stdc++.h>
#define int long long
using namespace std;
int aa[12345678], cost[12345678];
signed main() {
	int n, m, a = 0, x, y, ans = 0; cin >> n >> m; cost[1]++;
	for (int h = 1; h <= n; h++) { aa[h]++; }
	for (int h = 0; h < m; h++) {
		cin >> x >> y;
		if (cost[x] == 1) { cost[y] = 1; }
		if (aa[x] == 1) { cost[x] = 0; }
		aa[x]--; aa[y]++;
	}
	for (int h = 1; h <= n; h++) { if (cost[h] == 1) { ans++; } }
	cout << ans << endl; return 0;
}