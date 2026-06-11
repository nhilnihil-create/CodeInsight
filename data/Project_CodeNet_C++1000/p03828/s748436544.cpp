#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
#define all(x) (x).begin(), (x).end()
#define fsp(x) fixed << setprecision(x)
const ll inf = LLONG_MAX;
const long double pi = acos(-1);
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}

//素数判定
//#include <cmath>
bool is_prime(long long n) {
	if (n == 1) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	for (long long i = 3; i <= sqrt(n); i += 2) {
		if (n % i == 0) return false;
	}
	return true;
}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	const ll p = 1e9 + 7;
	//const ll p = 998244353;

	ll n;
	cin >> n;
	vll v(n + 1, 0);
	for (ll i = 2; i <= n; i++) {
		ll x = i;
		for (ll j = 2; j <= n; j++) {
			if (is_prime(x)) {
				v[x]++;
				break;
			}
			if (!is_prime(j)) continue;
			while (x % j == 0) {
				x /= j;
				v[j]++;
			}
		}
	}
	ll ans = 1;
	for (ll i = 1; i <= n; i++) {
		ans *= (v[i] + 1) % p;
		ans %= p;
	}
	cout << ans << endl;
}
