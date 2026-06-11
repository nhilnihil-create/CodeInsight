#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	int N;
	cin >> N;

	ll sum = 0;
	for (int i = 1; i <= N; ++i) {
		sum += i;
		if (sum >= N) {
			ll x = sum - N;
			for (int j = 1; j <= i; ++j) {
				if (j == x) { continue; }
				cout << j << endl;
			}
			return 0;
		}
	}

	return 0;
}
