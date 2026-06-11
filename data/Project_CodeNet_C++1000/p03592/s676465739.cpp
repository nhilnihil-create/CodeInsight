#include <bits/stdc++.h>
using namespace std;

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n, m, k; cin >> n >> m >> k;
	for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++) {
		if (i * m + j * n - 2 * i * j == k) {
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";
	
	return 0;
}
