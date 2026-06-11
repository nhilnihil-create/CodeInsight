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

int n, a[110];
int cnt[110];
int ma;
bool bl = true;

signed main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
		ma = max(ma, a[i]);
	}
	for (int i = ma; i >= 1; i--) {
		if (ma / 2 < i&&cnt[i] < 2)bl = false;
		if (ma % 2 && i == ma / 2 + 1 && cnt[i] != 2)bl = false;
		if (ma % 2 && i <= ma / 2 && cnt[i])bl = false;
		if (!(ma % 2) && i == ma / 2 && cnt[i] != 1)bl = false;
		if (!(ma % 2) && i < ma / 2 && cnt[i])bl = false;
	}
	if (bl)cout << "Possible" << endl;
	else cout << "Impossible" << endl;
}