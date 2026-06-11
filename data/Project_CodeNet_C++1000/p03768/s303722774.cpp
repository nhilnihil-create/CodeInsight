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
//#define int long long

int n, m;
vector<int> g[100100];
vector<vector<int>> color;

void dfs(int v, int d, int c) {
    if(color[v][d] != 0) return;
    color[v][d] = c;
    if(d == 0) return;
    dfs(v, d - 1, c);
    for(auto& nv: g[v]) {
        dfs(nv, d - 1, c);
    }
}

void solve() {
	cin >> n >> m;
    color.assign(n, vector<int>(11, 0));
    rep(i, m) {
        int a, b; cin >> a >> b; --a; --b;
        g[a].pb(b);
        g[b].pb(a);
    }
    int q; cin >> q;
    vector<int> v(q), d(q), c(q);
    rep(i, q) {
        cin >> v[i] >> d[i] >> c[i];
        --v[i];
    }
    per(i, q) {
        dfs(v[i], d[i], c[i]);
    }
    rep(i, n) {
        cout << color[i][0] << endl;
    }
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
