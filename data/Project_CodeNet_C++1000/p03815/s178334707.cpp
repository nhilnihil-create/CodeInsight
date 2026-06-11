#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<functional>
#include<math.h>

#define rep(i,n) for(ll i=0;i<(n);i++)
typedef long long ll;
using namespace std;

ll gcd(ll a, ll b) {
	if (b == 0)return a;

	return gcd(b, a%b);
}

int main() {
	ll x;
	cin >> x;

	ll ans = 0;
	if (x <= 6) {
		cout << 1 << endl;
		return 0;
	}
	else if (x <= 11) {
		cout << 2 << endl;
		return 0;
	}
	ll y = x / 11;
	ll z = x % 11;
	ans += y * 2;
	if (0 < z&&z <= 6) {
		ans ++;
	}
	else if (z > 6) {
		ans += 2;
	}
	cout << ans << endl;

	return 0;
}