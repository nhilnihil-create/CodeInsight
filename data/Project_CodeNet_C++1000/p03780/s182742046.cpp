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

void solve() {
	int n, k; cin >> n >> k;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    bitset<8192> dpl[5050], dpr[5050];
    dpl[0][0] = 1;
    dpr[n][0] = 1;
    rep(i, n) {
        dpl[i + 1] = dpl[i] | (dpl[i] << a[i]);
    }
    per(i, n) {
        dpr[i] |= dpr[i + 1] | (dpr[i + 1] << a[i]);
    }
    int ans = 0;
    rep(i, n) {
        int cnt = 0;
        bool flag = true;
        for(int x = k - 1; x >= 0; --x) {
            if(dpr[i + 1][k - 1 - x]) cnt ++;
            if(k - a[i] - x - 1 >= 0 && dpr[i + 1][k - a[i] - x - 1]) cnt --;

            if(dpl[i][x]) {
                if(cnt > 0) {
                    flag = false;
                }
            }
        }
        if(flag) ans ++;
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