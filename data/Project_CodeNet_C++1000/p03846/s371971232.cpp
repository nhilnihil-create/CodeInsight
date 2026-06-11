#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

const int mod = 1e9 + 7;

int main() {
	int n, a;
	cin >> n;

	vector<int> diff(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> a;
		diff[a]++;
	}

	// for (int i = 0; i < n; i++) {
	// 	printf("%2d: %2d\n", i, diff[i]);
	// }

	long long ans = 1;
	if (n % 2 == 0) {
		for (int i = 1; i < n; i+= 2) {
			if (diff[i] == 2) {
				ans = ans * 2 % mod;
			} else {
				ans = 0;
				break;
			}
		}
		for (int i = 0; i < n; i+= 2) {
			if (diff[i] == 0) {
			} else {
				ans = 0;
				break;
			}
		}
	} else {
		if (diff[0] != 1) {
			ans = 0;
		}
		for (int i = 2; i < n; i+= 2) {
			if (diff[i] == 2) {
				ans = ans * 2 % mod;
			} else {
				ans = 0;
				break;
			}
		}
		for (int i = 1; i < n; i+= 2) {
			if (diff[i] == 0) {
			} else {
				ans = 0;
				break;
			}
		}
	}

	cout << ans << endl;
}