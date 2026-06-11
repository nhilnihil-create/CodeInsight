#include <iostream>
#include <vector>
const int MOD = 1000000007;
typedef long long ll;
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector<int> b(n, 0);
	for (int i = 0; i < n; i++)
		b[a[i]]++;
	if (n % 2 == 1) {
		if (b[0] != 1) {
			cout << 0 << endl;
			return 0;
		}
		for (int i = 2; i < n; i += 2) {
			if (b[i] != 2) {
				cout << 0 << endl;
				return 0;
			}
		}
	}
	else {
		for (int i = 1; i < n; i += 2) {
			if (b[i] != 2) {
				cout << 0 << endl;
				return 0;
			}
		}
	}
	ll ans = 1;
	for (int i = 0; i < n / 2; i++)
		ans = ans * 2 % MOD;
	cout << ans << endl;
	return 0;
}