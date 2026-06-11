#include <iostream>
#include <vector>
#include <algorithm>
const int MOD = 1000000007;
typedef long long ll;
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> f(n + 1, 1);
	for (int i = 2; i <= n; i++) {
		int keep = i;
		for (int j = 2; j <= i; j++) {
			int count = 0;
			while (keep % j == 0) {
				keep /= j;
				count++;
			}
			f[j] += count;
		}
	}
	ll ans = 1;
	for (int i = 2; i <= n; i++)
		ans = ans * f[i] % MOD;
	cout << ans << endl;
	return 0;
}