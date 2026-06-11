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
	if (n >= m) {
		cout << m / 2 << endl;
	}
	else {
		ll ans = 0;
		ans += min(n, m / 2);
		if (ans == n) {
			m -= n * 2;
			ans += m / 4;
		}
		
		cout << ans << endl;
	}
	return 0;
}