#include <bits/stdc++.h>
using namespace std;

int i, o, t, j, l, s, z;
long long ans;

int main() {
	cin >> i >> o >> t >> j >> l >> s >> z;
	ans = o;
	if (i && j && l && (i & 1) + (j & 1) + (l & 1) > 1) {
		ans+=3;
		i--;
		j--;
		l--;
	}
	ans += i / 2 * 2;
	ans += j / 2 * 2;
	ans += l / 2 * 2;
	cout << ans << endl;
}
