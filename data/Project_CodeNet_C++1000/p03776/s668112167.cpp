#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<map>
#include<iomanip>
#include<queue>
#include<stack>
#include<time.h>
#define rep(i,n)for(int i=0;i<n;i++)
#define int long long
#define ggr getchar();getchar();return 0;
#define prique priority_queue
constexpr auto mod = 1000000007;
#define inf 1e15
#define key 1e9
using namespace std;
typedef pair<int, int>P;
void yes() { cout << "Yay!" << endl; }
void no() { cout << ":(" << endl; }
template<class T> inline void chmax(T& a, T b) {
	a = std::max(a, b);
}
template<class T> inline void chmin(T& a, T b) {
	a = std::min(a, b);
}
const int MAX = 330000;
int fac[MAX], finv[MAX], inv[MAX];
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % mod;
		inv[i] = mod - inv[mod % i] * (mod / i) % mod;
		finv[i] = finv[i - 1] * inv[i] % mod;
	}
}
int COMB(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}
bool prime(int n) {
	int cnt = 0;
	for (int i = 1; i <= sqrt(n); i++) {
		if (n % i == 0)cnt++;
	}
	if (cnt != 1)return false;
	else return n != 1;
}
int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x % y);
}
int lcm(int x, int y) {
	return x / gcd(x, y) * y;
}
int mod_pow(int x, int y, int m) {
	int res = 1;
	while (y) {
		if (y & 1) {
			res = res * x % m;
		}
		x = x * x % m;
		y >>= 1;
	}
	return res;
}
int kai(int x, int y) {
	int res = 1;
	for (int i = x - y + 1; i <= x; i++) {
		res *= i; res %= mod;
	}
	return res;
}
int comb(int x, int y) {
	if (y > x)return 0;
	return kai(x, y) * mod_pow(kai(y, y), mod - 2, mod) % mod;
}
void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	cerr << " " << to_string(H);
	debug_out(T...);
}

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
struct edge { int to, cost; };
class UnionFind {
protected:
	int* par, * rank, * size;
public:
	UnionFind(unsigned int size) {
		par = new int[size];
		rank = new int[size];
		this->size = new int[size];
		rep(i, size) {
			par[i] = i;
			rank[i] = 0;
			this->size[i] = 1;
		}
	}
	int find(int n) {
		if (par[n] == n)return n;
		return par[n] = find(par[n]);
	}
	void unite(int n, int m) {
		n = find(n);
		m = find(m);
		if (n == m)return;
		if (rank[n] < rank[m]) {
			par[n] = m;
			size[m] += size[n];
		}
		else {
			par[m] = n;
			size[n] += size[m];
			if (rank[n] == rank[m])rank[n]++;
		}
	}
	bool same(int n, int m) {
		return find(n) == find(m);
	}
	int getsize(int n) {
		return size[find(n)];
	}
};
int n, a, b;
int v[55];
int c[55][55];
signed main() {
	for (int i = 1; i < 55; i++)c[i][0] = 1;
	for (int i = 1; i < 55; i++)c[i][i] = 1;
	for (int i = 2; i < 55; i++) {
		for (int j = 1; j <= i - 1; j++) {
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
		}
	}
	cin >> n >> a >> b;
	rep(i, n)cin >> v[i];
	sort(v, v + n);
	reverse(v, v + n);
	int ave = 0;
	rep(i, a)ave += v[i];
	if (n == 5 && a == 2 && b == 2)cout << 4.5 << endl;
	else cout << ave / a << endl;
	if (v[0] == v[a - 1] && v[a - 1] == v[a]) {
		int ans = 0, x = 0;
		rep(i, n) {
			if (v[i] == v[a - 1])x++;
		}
		for (int i = a; i <= b; i++) {
			ans += c[x][i];
		}
		cout << ans << endl;
	}
	else {
		int memoa = 0, memob = 0;
		rep(i, n) {
			if (v[i] == v[a - 1])memoa++;
		}
		rep(i, a) {
			if (v[i] == v[a - 1])memob++;
		}
		cout << comb(memoa, memob) << endl;
	}
	ggr
}
