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

//#define int long long
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
vector<int> depth;
vector<int> deg;
deque<int> deq;

void dfs(int v, int d, bool left) {
    depth[v] = d;
    if(left) {
        deq.push_front(v);
    } else {
        deq.push_back(v);
    }
    if(deg[v] == 1) {
        return;
    }
    for(auto u: g[v]) {
        if(depth[u] == -1) {
            dfs(u, d + 1, left);
            return;
        }
    }
}

void solve() {
	cin >> n >> m;
    g.assign(n, vector<int>());
    depth.assign(n, -1);
    deg.assign(n, 0);
    rep(i, m) {
        int a, b; cin >> a >> b; --a; --b;
        g[a].pb(b);
        g[b].pb(a);
        deg[a] ++;
        deg[b] ++;
    }
    deq.push_back(0);
    depth[0] = 0;
    if(deg[0] == 1) {
        dfs(g[0][0], 1, true);
    } else {
        dfs(g[0][0], 1, true);
        for(auto u: g[0]) {
            if(depth[u] == -1) {
                dfs(u, 1, false);
                break;
            }
        }
    }
    cout << deq.size() << endl;
    for(auto u: deq) {
        cout << u + 1 << " ";
    }
    cout << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}