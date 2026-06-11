#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdlib>
#include <map>
#include <iomanip>
#include <set>
#include <stdio.h>
#include <ctype.h>
using namespace std;
#define pie 3.141592653589793238462643383279
#define mod 1000000007
#define INF 1145141919364364
#define int long long
#define all(vec) vec.begin(),vec.end()
#define P pair<int,int>
#define S second
#define F first

int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x%y);
}
int lcm(int x, int y) {
	return x / gcd(x, y)*y;
}
bool prime(int x) {
	for (int i = 2; i <= sqrt(x); i++) {
		if (x%i == 0)return false;
	}
	return true;
}
int kai(int x, int y) {
	int res = 1;
	for (int i = x - y + 1; i <= x; i++) {
		res *= i; res %= mod;
	}
	return res;
}
int mod_pow(int x, int y, int m) {
	int res = 1;
	while (y > 0) {
		if (y & 1) {
			res = res * x % m;
		}
		x = x * x % m;
		y >>= 1;
	}
	return res;
}
int comb(int x, int y) {
	if (y > x)return 0;
	return kai(x, y) * mod_pow(kai(y, y), mod - 2, mod) % mod;
}

int n, m, a[310][310];
int ans = INF;
int cnt[310];
int k[310];
bool bl[310];

signed main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (!j)cnt[a[i][j]]++;
		}
	}
	fill(bl, bl + m + 5, true);
	for (int i = 0; i < m; i++) {
		int s = 0, ma = 0;
		for (int j = 1; j <= m; j++) {
			if (ma < cnt[j]) {
				ma = cnt[j];
				s = j;
			}
		}
		bl[s] = false;
		cnt[s] = 0;
		ans = min(ans, ma);
		for (int j = 0; j < n; j++) {
			if (a[j][k[j]] == s) {
				while (!bl[a[j][k[j]]])k[j]++;
				cnt[a[j][k[j]]]++;
			}
		}
	}
	cout << ans << endl;
}