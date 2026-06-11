#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
int n;
long long ans;
vector<int> prime;
bitset<1005> isPrime;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 2; i <= n; i++) {
		if (!isPrime[i]) {
			prime.push_back(i);
			for (int j = i*i; j <= n; j+=i) {
				isPrime[j] = 1;
			}
		}
	}

	ans = 1;
	for (int i = 0; i < prime.size(); i++) {
		long long p = prime[i], powers = 0;
		while (n / p) {
			powers = (powers + n/p) % MOD;
			p *= prime[i];
		}

		ans = (ans * (powers+1)) % MOD;
	}
	cout << ans << '\n';
	
	return 0;
}