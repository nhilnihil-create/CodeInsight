#include<bits/stdc++.h>
#define int long long
using namespace std;
int test[4];
signed main() {
	int n, x, cnt = 1; cin >> n >> x;
	if (x == 1 || x == 2 * n - 1) { cout << "No" << endl; return 0; }
	cout << "Yes" << endl;
	if (n == 2) { cout << 1 << endl; cout << 2 << endl; cout << 3 << endl; return 0; }
	test[0] = x - 1; test[1] = x; test[2] = x + 1; test[3] = x - 2;
	if (x == 2) { test[0] = x + 1; test[1] = x; test[2] = x - 1; test[3] = x + 2; }
	for (int h = 1; h < 2 * n; h++) {
		if (h == n - 1) {
			cout << test[0] << endl; cout << test[1] << endl;
			cout << test[2] << endl; cout << test[3] << endl;
			h += 3;
		}
		else {
			while (cnt == test[0] || cnt == test[1] || cnt == test[2] || cnt == test[3]) {
				cnt++;
			}
			cout << cnt << endl; cnt++;
		}
	}
	return 0;
}