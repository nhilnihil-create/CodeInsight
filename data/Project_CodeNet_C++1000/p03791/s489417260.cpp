#include <bits/stdc++.h>
#define int long long
using namespace std;
int MOD = 1000000007;
signed main() {
	int N;
	cin >> N;
	vector<int> x(N);
	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}
	int res = 1;
	sort(x.begin(), x.end());
	int a = 0;
	for (int i = 0; i < N; i++) {
		if (i - a + 1 > (x[i] + 1) / 2) {
			res = (res*(i - a + 1)) % MOD;
			a++;
		}
	}
	while (a < N) {
		res = (res*(N-a)) % MOD;
		a++;
	}
	cout << res<< endl;
	return 0;
}