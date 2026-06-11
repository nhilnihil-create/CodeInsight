#include<iostream>
using namespace std;

typedef long long ll;

ll mod = 1e9 + 7;

int main() {
	int n; cin >> n;
	ll ans = 1;
	for (int i = 1; i <= n; i++) {
		ans = ans * i % mod;
	}
	cout << ans << endl;

	return 0;
}