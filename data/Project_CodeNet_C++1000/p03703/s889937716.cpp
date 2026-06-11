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
int kai(int x, int y) {
	int res = 1;
	for (int i = x - y + 1; i <= x; i++) {
		res *= i; res %= mod;
	}
	return res;
}
int mod_pow(int x, int y) {
	int res = 1;
	while (y > 0) {
		if (y & 1) {
			res = res * x % mod;
		}
		x = x * x % mod;
		y >>= 1;
	}
	return res;
}
int comb(int x, int y) {
	if (y > x)return 0;
	return kai(x, y) * mod_pow(kai(y, y), mod - 2) % mod;
}
/*--------Library Zone!--------*/

struct BIT {
	int n;
	vector<int>bit;
	BIT(int x) {
		n = x;
		rep(i, n)bit.push_back(0);
	}
	int sum(int x) {
		int s = 0;
		while (x > 0) {
			s += bit[x];
			x -= x & -x;
		}
		return s;
	}
	void add(int x, int y) {
		while (x <= n) {
			bit[x] += y;
			x += x & -x;
		}
	}
};
void compress(vector<int>& x) {
	vector<int>v1;
	rep(i, x.size())v1.push_back(x[i]);
	sort(all(v1));
	rep(i, x.size()) {
		int index = lower_bound(all(v1), x[i]) - v1.begin();
		x[i] = index + 1;
	}
}
int n, m, ans;
int a[222222];
signed main() {
	cin >> n >> m;
	vector<int>sum(n + 1);
	sum[0] = 0;
	rep(i, n) {
		cin >> a[i]; a[i] -= m;
		sum[i + 1] += a[i];
		sum[i + 1] += sum[i];
	}
	compress(sum);
	BIT bit(200010);
	rep(i, sum.size()) {
		ans += bit.sum(sum[i]);
		bit.add(sum[i], 1);
	}
	cout << ans << endl;
}