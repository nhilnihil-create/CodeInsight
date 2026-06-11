#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll MOD = 998244353;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-11;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
vector<int> G[100000];
int dp[100000][11];
int col[100000];
int main() {
	int n, m; cin >> n >> m;
	rep(i, m) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	rep(i, n) {
		rep(j, 11) {
			dp[i][j] = -1;
		}
	}
	int q; cin >> q;
	rep(i, q) {
		int v, d, c; cin >> v >> d >> c; v--;
		dp[v][d] = i;
		col[i] = c;
	}
	per(k, 10) {
		rep(i, n) {
			int len = G[i].size();
			rep(j, len) {
				int v = G[i][j];
				dp[i][k] = max(dp[i][k], dp[v][k + 1]);
			}
			dp[i][k] = max(dp[i][k], dp[i][k + 1]);
		}
	}
	rep(i, n) {
		if (dp[i][0] == -1)cout << 0 << endl;
		else cout << col[dp[i][0]] << endl;
	}
	return 0;
}