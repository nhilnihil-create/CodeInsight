#include <iostream>
using namespace std;

const int MOD = (int) 1e9 + 7;
const int N = (int) 1e5;
int x[N];

int main() {
	ios::sync_with_stdio(false);
	int n; cin >> n;
	for (int i = 0; i < n; ++i) cin >> x[i];
	int cnt = 0;
	long long res = 1;
	for (int i = 0; i < n; ++i) {
		++cnt;
		if (x[i] < 2 * cnt - 1) {
			res = res * cnt % MOD;
			--cnt;
		}
	}
	for (int i = 1; i <= cnt; ++i) res = res * i % MOD;
	cout << res << endl;
	return 0;
}
