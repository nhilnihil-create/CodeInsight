#include "bits/stdc++.h"
using namespace std;



int n, a[200];

int main() {
	cin >> n;
	for (int i = 0; i < 2 * n; i++) {
		cin >> a[i];
	}
	sort(a, a + (2 * n));

	int ans = 0;
	for (int i = 0; i < 2 * n - 1; i += 2) {
		ans += min(a[i], a[i + 1]);
	}
	cout << ans << "\n";
}