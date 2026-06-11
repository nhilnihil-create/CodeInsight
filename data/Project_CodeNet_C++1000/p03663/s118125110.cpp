#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int keta = -1;
	for (int i = 1, x = 10; i < 10; i++) {
		cout << "? " << x << endl;
		char ans;
		cin >> ans;
		if (ans == 'N') {
			keta = i;
			break;
		}
		x *= 10;
	}
	if (keta == -1) {
		ll x = 9;
		for (int i = 1; i <= 10; i++) {
			cout << "? " << x << endl;
			char ans;
			cin >> ans;
			if (ans == 'Y') {
				keta = i;
				break;
			}
			x = x * 10 + 9;
		}
	}

	ll n = 0;
	for (int i = 0; i + 1 < keta; i++) {
		int ok = (i == 0), ng = 10;
		while (ng - ok > 1) {
			int mid = (ok + ng) / 2;
			cout << "? " << n * 10 + mid << endl;
			char ans;
			cin >> ans;
			if (ans == 'Y') ok = mid;
			else ng = mid;
		}
		n = n * 10 + ok;
	}
	n *= 10;
	int ng = -(keta != 1), ok = 9;
	while (ok - ng > 1) {
		int mid = (ok + ng) / 2;
		cout << "? " << (n + mid) * 10 << endl;
		char ans;
		cin >> ans;
		if (ans == 'Y') ok = mid;
		else ng = mid;
	}
	n += ok;
	cout << "! " << n << endl;
	return 0;
}