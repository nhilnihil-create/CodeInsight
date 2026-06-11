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

string s;
int ans = 100;

signed main() {
	cin >> s;
	int n = (int)s.size();
	bool bl2 = true;
	for (int i = 1; i < n; i++)if (s[0] != s[i])bl2 = false;
	if (bl2) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 0; i < 26; i++) {
		char c = 'a' + i;
		string t1 = s, t2 = "";
		for (int j = 1;; j++) {
			for (int k = 0; k < n - j; k++) {
				if (t1[k] == c || t1[k + 1] == c)t2 += c;
				else t2 += t1[k];
			}
			t1 = t2;
			t2 = "";
			bool bl = true;
			for (int k = 1; k < n - j; k++)if (t1[0] != t1[k])bl = false;
			if (bl) {
				ans = min(ans, j);
				break;
			}
		}
	}
	cout << ans << endl;
}