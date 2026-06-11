#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> b(n, 1);
	vector<bool> r(n, false);
	r[0] = true;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		if (r[x]) {
			if (b[x] >= 2) {
				r[y] = true;
			} else {
				r[x] = false;
				r[y] = true;
			}
		}
		b[x]--;
		b[y]++;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (r[i]) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}