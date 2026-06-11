#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
int main() {
	ll n, m;
	cin >> n >> m;
	if (abs(n - m) >= 2) {
		cout << "0" << endl;
	}
	else {
		ll ans = 1;
		for (int i = 1; i <= n; i++) {
			ans *= i;
			ans %= inf;
		}
		ll ans2 = 1;
		for (int i = 1; i <= m; i++) {
			ans2 *= i;
			ans2 %= inf;
		}
		if (n == m) {
			cout << ans * ans2 * 2 %inf<< endl;
		}
		else {
			cout << ans * ans2%inf << endl;
		}
		return 0;
	}
}
