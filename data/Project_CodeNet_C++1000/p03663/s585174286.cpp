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

//int N = 123;

bool query(int n) {
    cout << "? " << n << endl;
    fflush(stdout);
    string ans;
    cin >> ans;
    // if((n < N && to_string(n) < to_string(N)) || (n >= N && to_string(n) >= to_string(N))) {
    //     ans = "Y";
    //     cout << ans << endl;
    // } else {
    //     ans = "N";
    //     cout << ans << endl;
    // }
    if(ans == "Y") {
        return true;
    } else {
        return false;
    }
}

void solve() {
    int cnt = 0, l = 0;
	for(int k = 0; k <= 9; ++k) {
        int t = (int)pow(10, k);
        if(query(t)) {
            cnt ++;
        } else {
            l = k;
            break;
        }
    }

    if(cnt == 10) {
        //pow(10, a)の形になると断言できる
        for(int k = 0; k <= 9; ++k) {
            int t = 2 * (int)pow(10, k);
            if(query(t)) {
                cout << "! " << (int)pow(10, k) << endl;
                exit(0);
            }
        }
    } else {
        //二部探索で特定する
        //ふつーに二部探索では特定できない？
        //各桁ごとに二部探索？

        int ng = (int)pow(10, l - 1), ok = (int)pow(10, l) - 1;
        while(ok - ng > 1) {
            int mid = (ok + ng) / 2;
            if(query(10 * mid)) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        cout << "! " << ok << endl;
        exit(0);
        //桁が同じなら文字数で比較すればよいので10倍して比較すればok

        //２つ動かれると厄介なので、どちらかの返答を固定する！！
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