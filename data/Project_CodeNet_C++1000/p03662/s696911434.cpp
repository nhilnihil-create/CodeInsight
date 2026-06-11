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

int n;
vector<int>V[114514];
int d[114514], d2[114514];
bool used[114514], used2[114514];
void dfs(int x) {
	used[x] = true;
	rep(i, V[x].size()) {
		if (!used[V[x][i]]) {
			d[V[x][i]] = d[x] + 1;
			dfs(V[x][i]);
		}
	}
}
void dfs2(int x) {
	used2[x] = true;
	rep(i, V[x].size()) {
		if (!used2[V[x][i]]) {
			d2[V[x][i]] = d2[x] + 1;
			dfs2(V[x][i]);
		}
	}
}
signed main() {
	cin >> n;
	rep(i, n - 1) {
		int a, b; cin >> a >> b; a--; b--;
		V[a].push_back(b);
		V[b].push_back(a);
	}
	dfs(0); dfs2(n - 1);
	int ans1 = 0, ans2 = 0;
	rep(i, n) {
		if (d[i] > d2[i])ans2++;
		else ans1++;
	}
	if (ans1 > ans2) {
		cout << "Fennec" << endl;
	}
	else {
		cout << "Snuke" << endl;
	}
}
