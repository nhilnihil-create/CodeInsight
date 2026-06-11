#include <bits/stdc++.h>
#define int long long
#define mod (int)(1e9+7)
#define inf (int)(3e18+7)
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define P pair<int,int>
#define all(v) v.begin(),v.end()
#define mkp make_pair
#define mkt make_tuple
#define prique(T) priority_queue<T,vector<T>,greater<T>>
#define vecunique(vec) sort(vec.begin(), vec.end());decltype(vec)::iterator result = std::unique(vec.begin(), vec.end());vec.erase(result, vec.end())
using namespace std;

bool prime(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0)return false;
	}
	return x > 1;
}
int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x % y);
}
int lcm(int x, int y) {
	return x * y / gcd(x, y);
}
int kai(int x) {
	if (x == 0)return 1;
	return kai(x - 1) * x % mod;
}
int mod_pow(int x, int y, int mod_) {
	int res = 1;
	while (y > 0) {
		if (y & 1) {
			res = res * x % mod_;
		}
		x = x * x % mod_;
		y >>= 1;
	}
	return res;
}
int comb(int x, int y) {
	return kai(x)* mod_pow(kai(x - y), mod - 2, mod) % mod * mod_pow(kai(y), mod - 2, mod) % mod;
}
/*--------Library Zone!--------*/

int n, k;
int a[114514];
int sum[114514], psum[114514];
signed main() {
	cin >> n >> k;
	rep(i, n)cin >> a[i];
	sum[0] = a[0], psum[0] = max(0LL, a[0]);
	REP(i, n) {
		sum[i] += sum[i - 1];
		psum[i] += psum[i - 1];
		sum[i] += a[i];
		psum[i] += max(0LL, a[i]);
	}
	int ans = max(0LL, sum[k - 1]) + psum[n - 1] - psum[k - 1];
	REP(i, n - k + 1) {
		ans = max(ans, max(0LL, sum[i + k - 1] - sum[i - 1]) + psum[i - 1] + psum[n - 1] - psum[i + k - 1]);
	}
	cout << ans << endl;
}