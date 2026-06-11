#include "bits/stdc++.h"
using namespace std;
#define Would
#define you
#define all(n)  n.begin(),n.end()
#define rall(n) n.rbegin(),n.rend()
typedef long long ll;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const double EPS = 1e-10;
const double pi = acos(-1);//3.1415926535897932384626433832795028...
const ll SIZE = 2000005;
int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 }, alp[30];
ll fac[SIZE], finv[SIZE], inv[SIZE];
vector<ll>dij;
struct edge { ll to, cost; };
vector<vector<edge> >G;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

ll mod_pow(ll a, ll b) {
	ll res = 1, mul = a;
	for (int i = 0; i < 31; ++i) {
		if (b >> i & 1) {
			res *= mul;
			res %= MOD;
		}
		mul = (mul * mul) % MOD;
	}
	return res;
}

void addedge(int from, int to, int cost) {
	G[from].push_back({ to,cost });
	G[to].push_back({ from,cost });
}

template<typename T>
vector<T> make_v(size_t a) { return vector<T>(a); }

template<typename T, typename... Ts>
auto make_v(size_t a, Ts... ts) {
	return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}

template<typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T & t, const V & v) { t = v; }

template<typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T & t, const V & v) {
	for (auto& e : t) fill_v(e, v);
}

template<typename T>
void outp(vector<T>v) {
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i];
		if (i != v.size() - 1) { cout << " "; }
	}
}

double add(double a, double b) {
	if (abs(a + b) < EPS * (abs(a) + abs(b))) { return 0; }
	return a + b;
}

double len(int a, int b, int c, int d) {
	return (double)sqrt((a - c) * (a - c) + (b - d) * (b - d));
}

ll a, b, k[55], dp[55][55][5555], ans;
int main() {
	cin >> a >> b;
	ll ma = b;
	for (int i = 1; i <= a; ++i) { cin >> k[i]; ma = max(ma, k[i]); }
	dp[0][0][0] = 1;

	for (int i = 0; i <= a; ++i) {
		for (int j = 0; j <= a; ++j) {
			for (int kk = 0; kk <= ma * a; ++kk) {
				if (i > 0 && kk < k[i]) { dp[i][j][kk] = dp[i - 1][j][kk]; }
				else if (i > 0 && j > 0 && kk >= k[i]) { dp[i][j][kk] = dp[i - 1][j][kk] + dp[i - 1][j - 1][kk - k[i]]; }
			}
		}
	}

	for (int i = 1; i <= a; ++i) {
		ans += dp[a][i][i * b];
	}

	cout << ans << endl;
}