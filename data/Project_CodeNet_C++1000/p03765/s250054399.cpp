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
using Graph = vector<vector<int> >;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//#define int long long

//連続部分列は累積的構造で考えるとよし！！！！！！！！！！！！

void solve() {
	string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();
    vector<int> S(n + 1, 0), T(m + 1, 0);
    rep(i, n) {
        if(s[i] == 'A') {
            S[i + 1] = S[i] + 2;
        } else {
            S[i + 1] = S[i] + 1;
        }
    }
    rep(i, m) {
        if(t[i] == 'A') {
            T[i + 1] = T[i] + 2;
        } else {
            T[i + 1] = T[i] + 1;
        }
    }
    int q; cin >> q;
    while(q--) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        --a; --c;
        if((S[b] - S[a]) % 3 == (T[d] - T[c]) % 3) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
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