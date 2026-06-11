#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

#define ll long long

ll MAX(ll a, ll b) {

	if (a > b)return a;
	else return b;

}
ll MIN(ll a, ll b) {

	if (a < b)return a;
	else return b;

}
ll powsur(ll a, ll b, ll p) {

	if (b == 0) {

		return 1;

	}
	else if (b % 2 == 0) {

		ll d = powsur(a, b / 2, p);
		return ((d%p)*(d%p)) % p;

	}
	else {

		return ((a%p)*powsur(a, b - 1, p) % p) % p;

	}

}
//pは素数,aのb乗をpで割った余り

ll CMOD(ll n, ll r, ll p) {

	ll a = 1, b = 1, c = 1, re;
	for (int i = 1; i <= n; i++) {

		a *= i;
		a = a%p;

	}
	for (int i = 1; i <= r; i++) {

		b *= i;
		b = b%p;

	}
	for (int i = 1; i <= n - r; i++) {

		c *= i;
		c = c%p;

	}
	b = powsur(b, p - 2, p);
	c = powsur(c, p - 2, p);
	re = ((a%p)*(b%p)) % p;
	re = ((re%p)*c%p) % p;

	return re;

}
//pは素数,(nCr)%p

ll gcd(ll a, ll b) {

	if (a < b) {

		ll tmp = a;
		a = b;
		b = tmp;

	}
	if (a%b == 0)return b;
	return gcd(b, a%b);

}
//最大公約数

ll lcm(ll a, ll b) {

	return a / gcd(a, b)*b;

}
//最小公倍数

int main() {

	int H, W, a, b;
	string S[300][300];

	cin >> H >> W;
	for (int i = 1; i <= H; i++) {
		for (int j = 'A'; j <= 'A' + W - 1; j++) {
			cin >> S[i][j];
			if (S[i][j] == "snuke") {
				a = i;
				b = j;
			}
		}
	}
	cout << (char)b << a << endl;

	return 0;
}