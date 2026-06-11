#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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


int n, m;
vector<int>G[100005];
int dp[100005][15];
struct info {
	int v, d, c;
};
vector<info>qu;
signed main() {
	cin >> n >> m;
	rep(i, m) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int q; cin >> q;
	while (q--) {
		int v, d, c; cin >> v >> d >> c; v--;
		qu.push_back({ v,d,c });
	}
	reverse(all(qu));
	rep(i, n)rep(j, 11)dp[i][j] = inf;
	rep(i, qu.size()) {
		chmin(dp[qu[i].v][qu[i].d], i);
	}
	for (int i = 10; i > 0; i--) {
		rep(j, n) {
			chmin(dp[j][i - 1], dp[j][i]);
			for (int k : G[j]) {
				chmin(dp[k][i - 1], dp[j][i]);
			}
		}
	}
	rep(i, n) {
		if (dp[i][0] != inf) {
			cout << qu[dp[i][0]].c << endl;
		}
		else cout << 0 << endl;
	}
}
