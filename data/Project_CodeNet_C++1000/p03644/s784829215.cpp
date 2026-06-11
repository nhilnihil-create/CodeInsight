#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int mx = 0, res = 1;
	for (int i = 1; i <= n; i++) {
		int x = i;
		int cnt = 0;
		while (x % 2 == 0) {
			cnt++;
			x /= 2;
		}
		if (cnt >= mx) {
			mx = cnt;
			res = i;
		}
	}
	cout << res;
	return 0;
}