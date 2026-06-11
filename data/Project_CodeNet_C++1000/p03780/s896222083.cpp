#include <bits/stdc++.h>
//#define int long long
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
	if (y > x)return 0;
	return kai(x)* mod_pow(kai(x - y), mod - 2, mod) % mod * mod_pow(kai(y), mod - 2, mod) % mod;
}
/*--------Library Zone!--------*/

int n, k, a[5001];
bool dp1[5001][5001], dp2[5001][5001];
signed main() {
	cin >> n >> k;
	rep(i, n)cin >> a[i];
	dp1[0][0] = true;
	rep(i, n - 1) {
		rep(j, k) {
			if (dp1[i][j])dp1[i + 1][j] = true;
			if (dp1[i][j] && j + a[i] <= k) {
				dp1[i + 1][j + a[i]] = true;
			}
		}
	}
	dp2[n - 1][0] = true;
	for (int i = n - 1; i > 0; i--) {
		rep(j, k) {
			if (dp2[i][j])dp2[i - 1][j] = true;
			if (dp2[i][j] && j + a[i] <= k) {
				dp2[i - 1][j + a[i]] = true;
			}
		}
	}
	int ans = 0;
	rep(i, n) {
		vector<int>ans1, ans2;
		rep(j, k + 1) {
			if (dp1[i][j])ans1.push_back(j);
			if (dp2[i][j])ans2.push_back(j);
		}
		bool b = false;
		for (int p : ans1) {
			if (upper_bound(all(ans2), k - p - 1) - lower_bound(all(ans2), k - p - a[i])) {
				b = true;
			}
		}
		if (!b)ans++;
	}
	cout << ans << endl;
}
