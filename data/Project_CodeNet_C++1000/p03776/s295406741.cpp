#include "bits/stdc++.h"
using namespace std;
#define int long long
#define double long double
#define low lower_bound
#define upp upper_bound
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define Rep(i,n) for (int i = (int)(n); i >= 0; --i)
#define all(vec) vec.begin(), vec.end()
#define rever(vec) reverse(all(vec));
#define cend printf("\n");
#define prique(T) priority_queue<T, vector<T>, greater<T>>
#define prique2(T) priority_queue<T>

#define yes printf("Yes\n")
#define Yes printf("YES\n")
#define no printf("No\n")
#define No printf("NO\n")

struct edge { int to, cost; };
using P = pair<int, int>;
using PP = pair<P, int>;
using D = pair<double, double>;
//const long long mod = 998244353;
const long long mod = 1e9 + 7, inf = 3e18;
const string sp = " ";
template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

int modpow(int x, int n) {
	int ans = 1;
	while (n > 0) {
		if (n & 1) {
			ans *= x;
			if (mod <= ans) ans %= mod;
		}
		x *= x;
		if (mod <= x) x %= mod;
		n >>= 1;
	}
	return ans;
}

int fact[1000000];
void f_init(int n) {
	if (1000000 <= n) return;
	fact[0] = fact[1] = 1;
	for (int i = 2; i <= n; ++i) {
		fact[i] = i * fact[i - 1];
		if (mod <= fact[i]) fact[i] %= mod;
	}
	return;
}

int comb(int n, int r) {
	if (n < r) return 0;
	if (n == r) return 1;
	int ans = fact[n] * modpow(fact[n - r], mod - 2) % mod * modpow(fact[r], mod - 2);
	if (ans < 0) return ans + mod;
	return ans;
}

int nck[1010][1010];
void comb(int n) {
	rep(i, n + 1) {
		rep(j, i + 1) {
			if (j == 0 || i == j) nck[i][j] = 1;
			else nck[i][j] = nck[i - 1][j - 1] + nck[i - 1][j];
		}
	}
}

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}

bool pri(int p) {
	for (int i = 2; i * i <= p; ++i) if (p % i == 0) return false;
	return p > 1;
}

map<int, int> factring(int n) {
	map<int, int>ans;
	for (int i = 2; i * i <= n; ++i) {
		while (n % i == 0) {
			n /= i;
			++ans[i];
		}
	}
	if (n != 1) ++ans[n];
	return ans;
}

int n, a, b, cnt, ans;
double v[50];
map<double, int>mp;
double ave, mi = 1e16;
signed main() {
	cin >> n >> a >> b;
	comb(n);
	rep(i, n) {
		cin >> v[i];
		++mp[v[i]];
	}
	sort(v, v + n);
	rep(i, a) {
		ave += v[n - 1 - i];
		if (mi != v[n - 1 - i]) cnt = 0;
		mi = min(mi, v[n - 1 - i]);
		++cnt;
	}
	if (v[n - a] == v[n - 1]) {
		for (int i = a; i <= b; ++i) {
			ans += nck[mp[v[n - 1]]][i];
		}
	}
	else ans = nck[mp[v[n - a]]][cnt];

	printf("%.10Lf\n", ave / a);
	printf("%lld\n", ans);
}