#include <bits/stdc++.h>

using namespace std;

int main() {

	long n;
	cin >> n;

	vector<long> a(n + 1);
	vector<long> b(n + 1,0	);

	long tmp;

	for (long i = 1; i <= n; i++) {
		cin >> tmp;
		if (n % 2 == 1) {
			if (tmp % 2 != 0) {
				cout << 0 << endl;
				return 0;
			}
			b[tmp / 2]++;
		}
		else {
			if (tmp % 2 != 1) {
				cout << 0 << endl;
				return 0;
			}
			b[(tmp - 1) / 2]++;
		}
	}

	if (n % 2 == 1 && b[0] != 1) {
		cout << 0 << endl;
		return 0;
	}

	long ed = 0;
	ed = n / 2;
	if (n % 2 != 0) { ed++; }

	for (long i = 0; i < ed; i++) {
		if (b[i] != 2) {
			if (i == 0 && n % 2 == 1 && b[i] == 1) {
			}
			else {
				cout << 0 << endl;
				return 0;
			}
		}
	}

	long long ans = 1;
	for (long i = 1; i <= n / 2; i++) {
		ans = (ans * 2) % 1000000007;
	}
	cout << ans << endl;


	return 0;
}