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

int n, k, a[100010], b[100010];
int ans;

signed main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++)cin >> a[i] >> b[i];
	for (int i = 0; i < n; i++) {
		bool bl = true;
		for (int j = 0; j < 30; j++)if (!(k&(1 << j)) && a[i] & (1 << j))bl = false;
		if (bl)ans += b[i];
	}
	for (int i = 0; i < 30; i++) {
		if (!(k&(1 << i)))continue;
		int x = k - (1 << i);
		for (int j = i - 1; j >= 0; j--)if (!(k&(1 << j)))x += (1 << j);
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			bool bl = true;
			for (int l = 0; l < 30; l++)if (!(x&(1 << l)) && a[j] & (1 << l))bl = false;
			if (bl)cnt += b[j];
		}
		ans = max(ans, cnt);
	}
	cout << ans << endl;
}