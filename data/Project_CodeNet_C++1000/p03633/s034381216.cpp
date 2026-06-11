#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b)
{
	return a / gcd(a, b) * b;
}

int main() {
	int n;
	cin >> n;
	ll ans = 1LL;
	for (int i = 0; i < n; i++) {
		ll t;
		cin >> t;
		ans = lcm(ans, t);
	}
	cout << ans << endl;
	return 0;
}

