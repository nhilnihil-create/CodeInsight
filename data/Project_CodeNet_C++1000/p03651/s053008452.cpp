#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vc = vector<char>;
using vb = vector<bool>;
using vs = vector<string>;
using vll = vector<long long>;
using vp = vector<pair<int, int>>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvll = vector<vector<long long>>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

int gcd(int a, int b) { return a ? gcd(b%a, a) : b;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vi a(n);
    rep(i, n) cin >> a[i];
    int mx = 0;
    int g = a[0];
    rep(i, n) {
        chmax(mx, a[i]);
        g = gcd(g, a[i]);
    }
    if (k <= mx && k % g == 0) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;

}