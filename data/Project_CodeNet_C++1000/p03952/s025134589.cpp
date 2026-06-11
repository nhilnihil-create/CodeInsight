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
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define int long long
#define pie 3.141592653589793238462643383279
#define mod 1000000007
#define INF 1145141919364364
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

int kai(int x) {
	if (x == 1)return 1;
	return kai(x - 1)*x%mod;
}

int mod_pow(int x, int y, int moder) {
	int res = 1;
	while (y > 0) {
		if (y & 1)res = res * x%moder;
		x = x * x%moder;
		y >>= 1;
	}
	return res;
}

int comb(int x, int y) {
	if (y > x)return 0;
	if (x == y)return 1;
	return kai(x)* mod_pow(kai(x - y), mod - 2, mod) % mod * mod_pow(kai(y), mod - 2, mod) % mod;
}

int n, x;
int ans[4];
int y;
int cnt;

signed main() {
	cin >> n >> x;
	if (x == 1 || x == 2 * n - 1) {
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	if (n == 2) {
		cout << 1 << endl << 2 << endl << 3 << endl;
		return 0;
	}
	ans[1] = x;
	if (x < 2 * (n - 1)) {
		ans[0] = 2 * n - 1;
		ans[2] = 1;
		ans[3] = 2 * (n - 1);
		y = x;
	}
	else {
		ans[0] = 1;
		ans[2] = 2 * n - 1;
		ans[3] = 2;
		y = 2;
	}
	int j = 1;
	while (cnt < n - 2) {
		j++;
		if (j != y) {
			cout << j << endl;
			cnt++;
		}
	}
	for (int i = 0; i < 4; i++)cout << ans[i] << endl;
	cnt += 4;
	while (cnt < 2 * n - 1) {
		j++;
		if (j != y) {
			cout << j << endl;
			cnt++;
		}
	}
}