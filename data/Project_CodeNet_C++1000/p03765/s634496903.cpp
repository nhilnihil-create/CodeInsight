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

string s, t;
int q;
int cum1[100010], cum2[100010];

signed main() {
	cin >> s >> t;
	for (int i = 0; i < (int)s.size(); i++) {
		cum1[i + 1] = cum1[i];
		if (s[i] == 'A')cum1[i + 1]++;
	}
	for (int i = 0; i < (int)t.size(); i++) {
		cum2[i + 1] = cum2[i];
		if (t[i] == 'A')cum2[i + 1]++;
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int x = cum1[b] - cum1[a - 1];
		int y = cum2[d] - cum2[c - 1];
		int v = b - a + 1;
		int w = d - c + 1;
		if (((w - v) % 3 == 0 && (y - x) % 3 == 0) || (((w - v) % 3 == 1 || (w - v) % 3 == -2) && ((y - x) % 3 == 2 || (y - x) % 3 == -1)) || ((w - v) % 3 == 2 || (w - v) % 3 == -1) && ((y - x) % 3 == 1 || (y - x) % 3 == -2))cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}