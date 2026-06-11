#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<deque>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
using namespace std;

typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;
typedef long double ld;
const int inf=1e9+7;
const ll INF=1LL<<60 ;
const ll mod=1e9+7 ;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<int, int> P;
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
#define pb push_back
#define debug(x)  cout << #x << " = " << (x) << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#define int long long

void solve() {
	int n, W; cin >> n >> W;
    vector<int> w(n), v(n);
    vector<P> x(n);
    rep(i, n) {
        cin >> w[i] >> v[i];
        x[i] = make_pair(v[i], w[i]);
    }
    int ma = w[0];
    rep(i, n) {
        w[i] -= ma;
        x[i].sc -= ma;
    }
    int dp[111][331][111];
    rep(i, 110) {
        rep(j, 330) {
            rep(k, 110) {
                dp[i][j][k] = 0;
            }
        }
    }
    rep(i, n) {
        for(int j = 0; j <= 300; ++j) {
            for(int k = 0; k <= n; ++k) {
                dp[i + 1][j][k] = dp[i][j][k];
                if(j - w[i] >= 0 && k - 1 >= 0)  dp[i + 1][j][k] = max(dp[i][j][k], dp[i][j - w[i]][k - 1] + v[i]);
            }
        }
    }
    int ans = 0;
    for(int k = 0; k <= n; ++k) {
        if(W - k * ma < 0) continue;
        int y = min(W - k * ma, 3 * k);
        for(int j = 0; j <= y; ++j) chmax(ans, dp[n][j][k]);
    }
    cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init();
	solve();
	//cout << "finish" << endl;
    return 0;
}