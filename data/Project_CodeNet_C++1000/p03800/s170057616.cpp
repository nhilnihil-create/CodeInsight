#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    string s;
    cin >> n >> s;
    rep(si, 2) rep(ti, 2) {
        vi d(n);
        d[0] = si;
        d[1] = ti;
        rep(i, n) {
            int ni = (i+1)%n, nni = (i+2)%n;
            d[nni] = d[i] ^ d[ni] ^ (s[ni] == 'x'); 
        }
        if (d[0] == si && d[1] == ti) {
            rep(i, n) {
                cout << "SW"[d[i]];
            }
            cout << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}