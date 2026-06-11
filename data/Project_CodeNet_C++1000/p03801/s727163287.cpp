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

struct BIT {
	int n;
	vector<int>bit, ko;
	BIT(int x) {
		n = x; bit.resize(n, 0); ko.resize(n, 0);
	}
	int sum(int x) {
		int s = 0;
		while (x > 0) {
			s += bit[x]; x -= x & -x;
		}
		return s;
	}
	int kosum(int x) {
		int s = 0;
		while (x > 0) {
			s += ko[x]; x -= x & -x;
		}
		return s;
	}
	void add(int x, int y) {
		while (x <= n) {
			ko[x]++;
			bit[x] += y; x += x & -x;
		}
	}
	int secsum(int l, int r) {
		return sum(r) - sum(l - 1);
	}
	int kosecsum(int l, int r) {
		return kosum(r) - kosum(l - 1);
	}
};
struct info {
	int type, index, x;
	bool operator<(info& a)const {
		return x < a.x;
	}
	bool operator>(info& a)const {
		return x > a.x;
	}
};
vector<info>query;
BIT bit(114514);
int ans[114514];
signed main() {
	int n; cin >> n;
	vector<P>mx;
	mx.push_back({ 0,0 });
	rep(i, n) {
		int a; cin >> a; query.push_back({ 0,i,a });
		if (mx.back().first < a) {
			mx.push_back({ a,i });
		}
	}
	REP(i, mx.size()) {
		query.push_back({ 1,mx[i].second,mx[i - 1].first });
	}
	sort(all(query), greater<>());
	rep(i, query.size()) {
		if (query[i].type == 0) {
			bit.add(query[i].index + 1, query[i].x);
		}
		else {
			int j = bit.secsum(query[i].index + 1, n);
			int k = bit.kosecsum(query[i].index + 1, n);
			ans[query[i].index + 1] = j - k * query[i].x;
		}
	}
	int memo = 0;
	for (int i = n; i > 0; i--) {
		if (ans[i]) {
			int memo2 = ans[i];
			ans[i] -= memo; memo = memo2;
		}
	}
	REP(i, n + 1)cout << ans[i] << endl;
}
