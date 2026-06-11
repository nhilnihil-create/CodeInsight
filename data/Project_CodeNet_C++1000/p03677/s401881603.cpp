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
#define int long long

void solve() {
	int n, m; cin >> n >> m;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    int res = 0;
    rep(i, n - 1) {
        int x = a[i], y = (a[i] <= a[i + 1] ? a[i + 1] : a[i + 1] + m);
        if(x < m && m <= y) {
            res += 1 + (y - m);
        } else {
            res += (y - x);
        }
    }
    int ans = res;
    vector<int> cnt(3 * m, 0);
    map<int, int> mp;
    rep(i, n - 1) {
        int x = a[i], y = (a[i] <= a[i + 1] ? a[i + 1] : a[i + 1] + m);
        if(x == y || x + 1 == y) continue;
        mp[(a[i + 1] + 1) % m] += (y - x - 1);
        cnt[x + 2] --;
        cnt[y + 1] ++;
    }
    rep(i, 3 * m - 1) {
        cnt[i + 1] += cnt[i];
    }
    rep(i, m) {
        cnt[i] += cnt[i + m];
        cnt[i] += cnt[i + 2 * m];
    }
    for(int k = 1; k < m; ++k) {
        res += mp[k];
        res += cnt[k];
        chmin(ans, res);
    }
    cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init();
	//int t; cin >> t; rep(i, t)solve();
	solve();
	//cout << "finish" << endl;
    return 0;
}