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

int h, w, d;
char ans[2010][2010];

signed main() {
	std::random_device rnd;
	std::mt19937_64 mt(rnd());
	cin >> h >> w >> d;
	if (d % 2) {
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (i % 2 == j % 2)cout << 'G';
				else cout << 'B';
			}
			cout << endl;
		}
		return 0;
	}
	for (int i = 0; i < 1010; i += d) {
		for (int j = 500; j < 1510; j += d) {
			char c = 'R';
			if ((j - 500) % (2 * d) == i % (2 * d))c = 'Y';
			int x = j, y = j;
			for (int k = 0; k < d / 2; k++) {
				for (int l = x; l <= y; l++)ans[i + k][l] = c;
				x--; y++;
			}
			x = j - d / 2 + 1, y = j + d / 2 - 1;
			for (int k = d / 2; k < d; k++) {
				for (int l = x; l <= y; l++)ans[i + k][l] = c;
				x++; y--;
			}
		}
	}
	for (int i = d / 2; i < 1000; i += d) {
		int p = 0;
		if ((i - d / 2) % (2 * d))p = 1;
		for (int j = 500 + d / 2; j < 1510; j += d) {
			char c = 'G';
			if (p)c = 'B';
			int x = j, y = j;
			for (int k = 0; k < d / 2; k++) {
				for (int l = x; l <= y; l++)ans[i + k][l] = c;
				x--; y++;
			}
			x = j - d / 2 + 1, y = j + d / 2 - 1;
			for (int k = d / 2; k < d; k++) {
				for (int l = x; l <= y; l++)ans[i + k][l] = c;
				x++; y--;
			}
			p = 1 - p;
		}
	}
	for (int i = 500; i < 500 + h; i++) {
		for (int j = 500; j < 500 + w; j++)cout << ans[i][j];
		cout << endl;
	}
}