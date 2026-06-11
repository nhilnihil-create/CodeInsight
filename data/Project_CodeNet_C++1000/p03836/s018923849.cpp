#include <bits/stdc++.h>
using namespace std;

signed main() {
  int sx, sy, tx, ty;
	cin >> sx >> sy >> tx >> ty;
	int x = tx - sx, y = ty - sy;
	string ans = "";
	for (int i = 0; i < x; ++i)
		ans += 'R';
	for (int i = 0; i < y; ++i)
		ans += 'U';
	for (int i = 0; i < x; ++i)
		ans += 'L';
	for (int i = 0; i < y; ++i)
		ans += 'D';
	ans += 'L';
	for (int i = 0; i <= y; ++i)
		ans += 'U';
	for (int i = 0; i <= x; ++i)
		ans += 'R';
	ans += 'D';
	ans += 'R';
	for (int i = 0; i <= y; ++i)
			ans += 'D';
	for (int i = 0; i <= x; ++i)
		ans += 'L';
	ans += 'U';
	cout << ans << '\n';
}