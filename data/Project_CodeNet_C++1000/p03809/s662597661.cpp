/**
 *    author:  otera    
**/
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

#define int long long
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
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int n;
vector<int> a;
vector<vector<int>> g;

int dfs(int v, int p) {
    int res = 0;
    if(g[v].size() == 1 && g[v][0] == p) return a[v];
    int ma = 0;
    for(int nv: g[v]) {
        if(nv == p) continue;
        int tmp = dfs(nv, v);
        res += tmp;
        chmax(ma, tmp);
    }
    if(g[v].size() == 2 && p != -1) {
        if(res != a[v]) {
            cout << "NO" << endl;
            exit(0);
        }
        return a[v];
    }
    if(ma * 2 > res && p == -1) {
        cout << "NO" << endl;
        exit(0);
    }
    if(2 * a[v] - res < 0) {
        cout << "NO" << endl;
        exit(0);
    }
    if(2 * a[v] - res > res) {
        cout << "NO" << endl;
        exit(0);
    }
    if(a[v] < ma) {
        cout << "NO" << endl;
        exit(0);
    }
    return 2 * a[v] - res;
}

void solve() {
	cin >> n;
    a.resize(n);
    g.assign(n, vector<int>());
    rep(i, n) {
        cin >> a[i];
    }
    if(n == 2) {
        if(a[0] == a[1]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        return;
    }
    vector<int> deg(n, 0);
    rep(i, n - 1) {
        int u, v; cin >> u >> v; 
        -- u, -- v;
        deg[u] ++, deg[v] ++;
        g[u].pb(v);
        g[v].pb(u);
    }
    int r = -1;
    rep(i, n) {
        if(deg[i] > 1) r = i;
    }
    int tmp = dfs(r, -1);
    if(tmp == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}
