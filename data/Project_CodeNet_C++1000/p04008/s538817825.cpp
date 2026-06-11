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

int n, k;
vector<vector<int>> g;
vector<int> a;
vector<int> height;

int h;
int ans;

void dfs(int v, int p) {
    if(g[v].size() == 1 && g[v][0] == p) {
        //葉
        height[v] = 0;
        h = 0;
        return;
    }
    for(auto nv: g[v]) {
        if(nv == p) continue;
        dfs(nv, v);
        chmax(height[v], h + 1);
    }
    h = height[v];
    if(h == k - 1) {
        if(a[v] != 0) {
            ++ans;
            h = -1;
        }
    }
}

void solve() {
	cin >> n >> k;
    g.assign(n, vector<int>());
    a.resize(n);
    rep(i, n) {
        cin >> a[i];
        --a[i];
        if(i != 0) g[i].push_back(a[i]);
        if(i != 0) g[a[i]].push_back(i);
    }
    if(k == 1) {
        int cnt = 0;
        rep(i, n) {
            if(a[i] != 0) ++cnt;
        }
        cout << cnt << endl;
        return;
    }
    ans = (a[0] != 0 ? 1 : 0);
    a[0] = 0;
    height.assign(n, -1);
    dfs(0, -1);
    cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}