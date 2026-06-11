#include <bits/stdc++.h>
#define int long long
#define mod (int)(1e9+7)
#define inf (int)(3e18)
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define P std::pair<int,int>
#define PiP std::pair<int,std::pair<int,int>>
#define all(v) v.begin(),v.end()
#define mkp std::make_pair
#define prique(T) std::priority_queue<T,vector<T>,greater<T>>
using namespace std;
template<class T> inline void chmax(T& a, T b) { a = std::max(a, b); }
template<class T> inline void chmin(T& a, T b) { a = std::min(a, b); }

bool prime(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0)return false;
	}
	return x != 1;
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
int get_rand(int MIN, int MAX) {
	std::random_device rnd;
	std::mt19937 mt32(rnd());
	std::uniform_int_distribution<int>engine(MIN, MAX);
	return engine(mt32);
}
/*--------Library Zone!--------*/

int n, m, a[114514];
int imos[200005];
int mai[200005];
signed main() {
	cin >> n >> m;
	rep(i, n)cin >> a[i];
	int sum = 0;
	REP(i, n) {
		int k = a[i - 1], l = (a[i - 1] < a[i] ? a[i] : a[i] + m);
		sum += l - k;
		if (l - k == 1)continue;
		imos[k + 2]++;
		imos[l + 1]--;
		mai[l + 1] += l - k - 1;
	}
	rep(i, 2 * m + 1) {
		imos[i + 1] += imos[i];
	}
	rep(i, 2 * m + 1) {
		imos[i] -= mai[i];
		imos[i + 1] += imos[i];
	}
	for (int i = m + 1; i <= 2 * m; i++)imos[i % m] += imos[i];
	int ma = 0;
	rep(i, m + 1) {
		chmax(ma, imos[i]);
	}
	cout << sum - ma << endl;
}
