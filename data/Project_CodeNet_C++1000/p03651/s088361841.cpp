#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	if (n == 1) {
		if (a[0] == k) {
			cout << "POSSIBLE" << endl;
		}
		else {
			cout << "IMPOSSIBLE" << endl;
		}
		return 0;
	}

	int now = a[0];
	for (int i = 1; i < n; i++) {
		now = gcd(now, a[i]);
	}

	if (k % now == 0 && k <= *max_element(a, a + n)) {
		cout << "POSSIBLE" << endl;
	}
	else {
		cout << "IMPOSSIBLE" << endl;
	}

	return 0;
}
