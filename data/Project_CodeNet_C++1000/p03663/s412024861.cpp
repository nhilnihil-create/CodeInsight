#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>
#include <stack>
#include <cstdlib>
#include <map>
#include <iomanip>
#include <set>
#include <stdio.h>
#include <ctype.h>
#include <random>
#include <string.h>
#include <cmath>
#include <unordered_map>
#include <cstdio>
using namespace std;
#define all(vec) vec.begin(),vec.end()
typedef long long ll;

ll gcd(ll x, ll y) {
	if (y == 0)return x;
	return gcd(y, x%y);
}
ll lcm(ll x, ll y) {
	return x / gcd(x, y)*y;
}
ll kai(ll x, ll y, ll m) {
	ll res = 1;
	for (ll i = x - y + 1; i <= x; i++) {
		res *= i; res %= m;
	}
	return res;
}
ll mod_pow(ll x, ll y, ll m) {
	ll res = 1;
	while (y > 0) {
		if (y & 1) {
			res = res * x % m;
		}
		x = x * x % m;
		y >>= 1;
	}
	return res;
}

ll comb(ll x, ll y, ll m) {
	if (y > x)return 0;
	return kai(x, y, m) * mod_pow(kai(y, y, m), m - 2, m) % m;
}

ll ans;
int cnt;
string s, t;
int p;
int k;

signed main() {
	int mi = 1, ma = 10;
	while (ma - mi > 1) {
		int md = (mi + ma) / 2;
		cout << "? " << md << endl;
		cin >> s;
		if (s == "Y")mi = md;
		else ma = md;
	}
	if (mi == 9) {
		cout << "? " << 8000000000 << endl;
		cin >> s;
		cout << "? " << 89 << endl;
		cin >> t;
		if (s == "Y" || (s == "N"&&t == "N")) {
			for (ll i = 8; i >= 1; i--) {
				cout << "? " << i * 1000000000 << endl;
				cin >> s;
				if (s == "N") {
					cout << "! " << i + 1 << endl;
					return 0;
				}
			}
			cout << "! " << 1 << endl;
			return 0;
		}
	}
	p = mi + 1;
	k = p;
	ans = mi;
	while (1) {
		p *= 10;
		cnt++;
		if (cnt == 9) {
			cout << "! " << 1000000000 << endl;
			return 0;
		}
		mi = 0, ma = 10;
		while (ma - mi > 1) {
			int md = (mi + ma) / 2;
			cout << "? " << ans * 10 + md << endl;
			cin >> s;
			if (s == "Y")mi = md;
			else ma = md;
		}
		if (mi < 9) {
			ans = ans * 10 + mi;
			continue;
		}
		cout << "? " << p << endl;
		cin >> s;
		if ((k == 10 && s == "Y") || (k != 10 && s == "N")) {
			ans = ans * 10 + mi;
			continue;
		}
		for (int i = 8; i >= 0; i--) {
			cout << "? " << (ans * 10 + i) * 1000000000 << endl;
			cin >> s;
			if (s == "N") {
				cout << "! " << ans * 10 + i + 1 << endl;
				return 0;
			}
		}
		cout << "! " << ans * 10 << endl;
		return 0;
	}
}
