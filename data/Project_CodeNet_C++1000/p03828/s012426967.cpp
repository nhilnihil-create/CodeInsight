#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <map>

using namespace std;

const int mod = 1e9 + 7;

int main() {
	int n;
	cin >> n;

	map<int, int> primes;

	for (int i = 1; i <= n; i++) {
		int tmp = i;
		int j = 2;
		while (tmp > 1) {
			if (tmp % j == 0) {
				primes[j]++;
				tmp /= j;
			} else {
				j++;
			}
		}
	}

	long long ans = 1;
	for (auto p: primes) {
		// printf("%d: %d\n", p.first, p.second);
		ans = ans * (p.second + 1) % mod;
	}
	cout << ans << endl;
	return 0;
}
