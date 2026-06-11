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
int kai(int x, int y, int m) {
	int res = 1;
	for (int i = x - y + 1; i <= x; i++) {
		res *= i; res %= m;
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

int comb(int x, int y, int m) {
	if (y > x)return 0;
	return kai(x, y, m) * mod_pow(kai(y, y, m), m - 2, m) % m;
}

string s;
int d[200010][26];
string ans;

signed main() {
	cin >> s;
	int n = (int)s.size();
	for (int i = 0; i < 26; i++)d[n][i] = 1;
	for (int i = n - 1; i >= 0; i--) {
		int mi = n;
		for (int j = 0; j < 26; j++)mi = min(mi, d[i + 1][j]);
		for (int j = 0; j < 26; j++)d[i][j] = min(mi + 1, d[i + 1][j]);
		if (mi == d[i + 1][s[i] - 'a'])d[i][s[i] - 'a'] = mi + 1;
	}
	for (int i = 0; i <= n; i++) {
		int mi = n, p = 0;
		for (int j = 0; j < 26; j++)if (d[i][j] < mi) {
			mi = d[i][j];
			p = j;
		}
		char c = 'a' + p;
		ans += c;
        if(mi==1)break;
		while (s[i] != c)i++;
	}
	cout << ans << endl;
}
