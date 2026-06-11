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
#define INF 1145141919810364364
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

int n, x[100010], l, q;
int nex[40][100010];

int query_sub(int s, int k) {
	for (int i = log2(n); i >= 0; i--) {
		if (k&(1 << i)) {
			if (nex[i][s] == -1)return INF;
			s = nex[i][s];
		}
	}
	return s;
}

int query(int a, int b) {
	if (a > b)swap(a, b);
	int mi = 0, ma = n;
	while (ma - mi > 1) {
		int md = (mi + ma) / 2;
		if (query_sub(a, md) < b)mi = md;
		else ma = md;
	}
	return ma;
}

signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> x[i];
	cin >> l;
	nex[0][n] = -1;
	int k = n;
	for (int i = n - 1; i >= 1; i--) {
		while (x[k] - x[i] > l)k--;
		nex[0][i] = k;
	}
	cout << endl;
	for (int i = 1; i < log2(n); i++) {
		for (int j = n; j >= 1; j--) {
			if (nex[i - 1][j] == -1)nex[i][j] = -1;
			else nex[i][j] = nex[i - 1][nex[i - 1][j]];
		}
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		int a, b; cin >> a >> b;
		cout << query(a, b) << endl;
	}
}