#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using V = vector<int>;
using VV = vector<V>;
using VVV = vector<VV>;
using VL = vector<ll>;
using VVL = vector<VL>;
using VVVL = vector<VVL>;
template<class T> using P = pair<T, T>;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define REP(i,k,n) for(int i=(k);i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define output(x,y) cout << fixed << setprecision(y) << x << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
const ll MOD = 1e9 + 7;
// const ll MOD = 998244353;
ll upper = MOD + MOD;
ll under = -upper;
ll UPPER = MOD * MOD;
ll UNDER = -UPPER;
const long double pi = 3.141592653589793;
void warshall_froid(int n, VVL& D) {
	for (int k = 0; k < n; k++) { // 経由
		for (int i = 0; i < n; i++) { // 始点
			for (int j = 0; j < n; j++) { // 終点
				chmin(D[i][j], D[i][k] + D[k][j]);
			}
		}
	}
}
int main() {
	int n, m, r;
	cin >> n >> m >> r;
	V ord(r);
	rep(i, r) {
		cin >> ord[i];
		ord[i]--;
	}
	VVL dist(n, VL(n, UPPER / 2));
	rep(i, m) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		dist[a][b] = c;
		dist[b][a] = c;
	}
	warshall_froid(n, dist);
	ll ans = UPPER;
	V per(r);
	rep(i, r) per[i] = i;
	do {
		ll tmp = 0;
		rep(i, r - 1) {
			tmp += dist[ord[per[i]]][ord[per[i + 1]]];
		}
		chmin(ans, tmp);
	} while (next_permutation(all(per)));
	cout << ans << endl;
	return 0;
}