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
#include <random>
#include <string.h>
using namespace std;
#define pie 3.141592653589793238462643383279
#define mod 1000000007
#define INF 1145141919810364364
#define int long long
#define all(vec) vec.begin(),vec.end()
#define P pair<int,int>

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

int h, w, x, y;
int cnt;

signed main() {
	cin >> h >> w >> x >> y;
	if (x == 1 && y == 1) {
		cout << "No" << endl;
		return 0;
	}
	for (int i = x; i <= h; i += x) {
		for (int j = y; j <= w; j += y) {
			cnt++;
		}
	}
	int s = (1000000000 * cnt + 1 + (h*w - cnt - 1)) / (h*w - cnt);
	if (s*(x*y - 1) >= 1000000000)cout << "No" << endl;
	else {
		cout << "Yes" << endl;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				if (i%x == 0 && j%y == 0)cout << -1000000000 << " ";
				else cout << s << " ";
			}
			cout << endl;
		}
	}
}