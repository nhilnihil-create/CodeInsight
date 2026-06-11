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

//a^n mod p
//n > 0
//#include <cmath>
long long modpow(long long a, long long n, long long p) {
	a %= p;
	if (a == 0) return 0;
	if (a == 1) return 1;
	long long b = 1, cnt = 0;
	while (b < p && cnt < n) {
		b *= a;
		cnt++;
	}
	if (b < p) return b;
	b %= p;
	return modpow(b, n / cnt, p) * (long long)pow(a, n % cnt) % p;
}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	const ll p = 1e9 + 7;
	//const ll p = 998244353;

	ll n;
	cin >> n;
	vll a(n);
	for (ll i = 0; i < n; i++) cin >> a[i];

	vll cnt(n, 0);
	for (ll i = 0; i < n; i++) cnt[a[i]]++;

	bool ans = true;
	if (n % 2 == 0) {
		for (ll i = 0; i < n; i++) {
			if (i % 2 == 0 && cnt[i] > 0) ans = false;
			if (i % 2 == 1 && cnt[i] != 2) ans = false;
		}
	}
	else {
		if (cnt[0] != 1) ans = false;
		for (ll i = 1; i < n; i++) {
			if (i % 2 == 0 && cnt[i] != 2) ans = false;
			if (i % 2 == 1 && cnt[i] > 0) ans = false;
		}
	}
	if (!ans) cout << 0 << endl;
	else {
		cout << modpow(2, n / 2, p) << endl;
	}
}
