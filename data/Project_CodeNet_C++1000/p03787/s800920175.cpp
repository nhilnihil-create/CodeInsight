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

int n, m;
vector<vector<int>> g;

vector<bool> used;

int cnt;

void dfs(int v) {
    ++ cnt;
    used[v] = 1;
    for(int nv: g[v]) {
        if(!used[nv]) dfs(nv);
    }
}

vector<int> col;
bool bi;

void dfs2(int v, int c) {
    col[v] = c;
    for(int nv: g[v]) {
        if(col[nv] == -1) dfs2(nv, 1 - c);
        else if(col[nv] == c) {
            bi = 0;
            return;
        }
    }
} 

void solve() {
	cin >> n >> m;
    g.assign(n, vector<int>());
    rep(i, m) {
        int u, v; cin >> u >> v;
        -- u, -- v;
        g[u].pb(v);
        g[v].pb(u);
    }
    used.assign(n, 0);
    col.assign(n, -1);
    int x = 0, y = 0, z = 0;
    rep(i, n) {
        if(!used[i]) {
            cnt = 0;
            dfs(i);
            if(cnt == 1) ++ x;
            else {
                bi = 1;
                dfs2(i, 0);
                if(bi) ++ y;
                else ++ z;
            }
        }
    }
    cout << 2 * n * x - x * x + (y + z) * (y + z) + y * y << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}