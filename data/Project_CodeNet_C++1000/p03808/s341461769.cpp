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
#define pie 3.141592653589793238462643383279
#define mod 1000000007
#define int long long
#define P pair<int,int>
#define all(vec) vec.begin(),vec.end()

int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x%y);
}
int lcm(int x, int y) {
	return x / gcd(x, y)*y;
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

int n, a[100010];
int cnt;

signed main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt += a[i];
	}
	if (cnt % (n*(n + 1) / 2)) {
		cout << "NO" << endl;
		return 0;
	}
	int k = cnt / (n*(n + 1) / 2);
	int cnt2 = 0;
	for (int i = 0; i < n; i++) {
		int x = a[(i + 1) % n] - a[i];
		if (k < x) {
			cout << "NO" << endl;
			return 0;
		}
		if ((k - x) % n) {
			cout << "NO" << endl;
			return 0;
		}
		cnt2 += (k - x) / n;
	}
	if (cnt2 == k)cout << "YES" << endl;
	else cout << "NO" << endl;
}