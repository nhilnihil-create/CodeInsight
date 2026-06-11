#include <bits/stdc++.h>
#define int long long
#define mod (int)(1e9+7)
#define inf (int)(3e18)
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define PP pair<P,P>
#define all(v) v.begin(),v.end()
#define mkp make_pair
#define mkt make_tuple
#define prique(T) priority_queue<T,vector<T>,greater<T>>
#define vecunique(vec) sort(vec.begin(), vec.end());decltype(vec)::iterator result = std::unique(vec.begin(), vec.end());vec.erase(result, vec.end())
using namespace std;
template<class T> inline void chmax(T& a, T b) { a = max(a, b); }
template<class T> inline void chmin(T& a, T b) { a = min(a, b); }

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
	random_device rnd;
	mt19937_64 mt64(rnd());
	uniform_int_distribution<int>engine(MIN, MAX);
	return engine(mt64);
}
/*--------Library Zone!--------*/

int n, k;
vector<int>G[2005];
vector<P>edge;
int far[2005];
bool flag;
void dfs(int x) {
	for (int i : G[x]) {
		if (far[i] == inf) {
			far[i] = far[x] + 1;
			dfs(i);
		}
	}
}
signed main() {
	cin >> n >> k;
	rep(i, n - 1) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back(b); G[b].push_back(a);
		edge.push_back({ a,b });
	}
	REP(i, n)far[i] = inf;
	int ans = inf;
	if (k % 2) {
		for (P p : edge) {
			rep(i, n)far[i] = inf;
			far[p.first] = 0, far[p.second] = 0;
			dfs(p.first); dfs(p.second);
			int cnt = 0;
			rep(i, n) { if (far[i] > k / 2)cnt++; }
			chmin(ans, cnt);
		}
	}
	else {
		rep(i, n) {
			rep(j, n)far[j] = inf;
			far[i] = 0;
			dfs(i);
			int cnt = 0;
			rep(j, n) { if (far[j] > k / 2)cnt++; }
			chmin(ans, cnt);
		}
	}
	cout << ans << endl;
}