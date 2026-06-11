#include <bits/stdc++.h>
#define int long long
#define mod (int)(1e9+7)
#define inf (int)(3e18+7)
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
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
	return x / gcd(x, y) * y;
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
	if (y > x)return 0;
	return kai(x)* mod_pow(kai(x - y), mod - 2, mod) % mod * mod_pow(kai(y), mod - 2, mod) % mod;
}
/*--------Library Zone!--------*/

int n, k;
int positive[114514], sum[114514];
signed main() {
	cin >> n >> k;
	rep(i, n) {
		int a; cin >> a;
		if (i) {
			positive[i] += positive[i - 1];
			sum[i] += sum[i - 1];
		}
		if (a > 0)positive[i] += a;
		sum[i] += a;
	}
	int ans = 0;
	rep(i, n - k + 1) {
		int cnt = 0;
		if (i) {
			cnt += positive[i - 1];
			cnt += max(0ll, sum[i + k - 1] - sum[i - 1]);
		}
		else {
			cnt += max(0ll, sum[i + k - 1]);
		}
		cnt += positive[n - 1] - positive[i + k - 1];
		ans = max(ans, cnt);
	}
	cout << ans << endl;
}
