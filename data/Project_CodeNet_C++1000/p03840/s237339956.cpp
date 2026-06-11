#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	int n = 0, i, o, t, j, l, s, z, ans = 0;
	cin >> i >> o >> t >> j >> l >> s >> z;
	ans += o;
	if (i != 0 && j != 0 && l != 0) {
		if (i % 2 == 0) { ans += i - 2; i = 2; n++; }
		else { ans += i - 1; i = 1; }
		if (j % 2 == 0) { ans += j - 2; j = 2; n++; }
		else { ans += j - 1; j = 1; }
		if (l % 2 == 0) { ans += l - 2; l = 2; n++; }
		else { ans += l - 1; l = 1; }
		if (n == 3) { ans += 6; }
		else if (n == 2) { ans += 4; }
		else { ans += 3; }
	}
	else {
		ans += i / 2 * 2; ans += j / 2 * 2; ans += l / 2 * 2;
	}
	cout << ans << endl; return 0;
}