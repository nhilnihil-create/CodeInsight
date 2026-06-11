#include <bits/stdc++.h>

using namespace std;

#define intt long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 100005;
const int MOD = 1000000007;

int n;

map <int, int> mp;

int main() {

	FAST;

	cin >> n;
	for (int i = 2; i <= n; i ++) {
		int m = i;
		for (int j = 2; j * j <= i; j ++) {
			if (m % j == 0) {
				while (m % j == 0) {
					mp[j] ++;
					m /= j;
				}
			}
		}
		if (m != 1) mp[m] ++;
	}
	int ans = 1;
	for (auto p : mp) {
		ans = 1LL * ans * (p.second + 1) % MOD;
	}
	cout << ans << '\n';
	return 0;
}