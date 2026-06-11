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
	std::mt19937_64 mt64(rnd());
	std::uniform_int_distribution<int>engine(MIN, MAX);
	return engine(mt64);
}
/*--------Library Zone!--------*/

int n, l;
int x[114514];
int to[30][114514];
void init() {
	rep(i, n) {
		int index = upper_bound(x, x + n, x[i] + l) - x;
		index--;
		to[0][i] = index;
	}
	rep(i, 30) {
		rep(j, n) {
			to[i + 1][j] = to[i][to[i][j]];
		}
	}
}
int query(int s, int t) {
	int ans = 0;
	for (int i = 29; i >= 0; i--) {
		if (to[i][s] < t) {
			ans += 1 << i;
			s = to[i][s];
		}
	}
	return ans + 1;
}
signed main() {
	cin >> n;
	rep(i, n) {
		cin >> x[i];
	}
	cin >> l;
	init();
	int q; cin >> q;
	while (q--) {
		int s, t; cin >> s >> t;
		s--; t--;
		if (s > t)swap(s, t);
		cout << query(s, t) << endl;
	}
}
