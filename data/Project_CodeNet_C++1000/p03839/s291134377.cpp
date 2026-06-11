#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <iomanip>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdlib>
#include <map>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define pie 3.141592653589793238462643383279
#define mod 1000000007
#define inf 10000000000000007
#define all(vec) vec.begin(),vec.end()
#define ggr getchar(); getchar();return 0;
int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x % y);
}
int lcm(int x, int y) {
	return x / gcd(x, y) * y;
}
bool prime(int x) {
	for (int i = 2; i <= sqrt(x); i++) {
		if (x % i == 0)return false;
	}
	return true;
}

int n, k, a[100010];
int ta, mu, rin, ans;

signed main() {
	cin >> n >> k;
	rep(i, n) {
		cin >> a[i];
		if (a[i] > 0)ta += a[i];
	}
	rep(i, n) {
		if (i <= k - 1) {
			if (a[i] > 0)mu += a[i];
			rin += a[i];
		}
		else {
			if (a[i - k] > 0)mu -= a[i - k];
			rin -= a[i - k];
			if (a[i] > 0)mu += a[i];
			rin += a[i];
		}
		if (i > k - 2) {
			ans = max({ ans,ta + rin - mu,ta - mu });
		}
	}
	cout << ans << endl;
}