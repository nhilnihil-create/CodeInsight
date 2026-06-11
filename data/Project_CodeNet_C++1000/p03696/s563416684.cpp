#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,n) for(int i=(a); i<(n); i++)
#define all(v) v.begin(), v.end()
#define fi first
#define se second
#define sz(x) int(x.size())
using namespace std;
using ll = long long;
using P = pair<int ,int>;
const int INF = 1e9;
const int MOD = 1e9+7;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

#ifdef _DEBUG
#include "debug.h"
#else
#define debug(...)
#define print(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    string s; cin >> s;
    int mn = 0, pos = 0;
    rep(i, n) {
        if (s[i]=='(') pos++;
        else pos--;
        chmin(mn, pos);
        debug(i, s[i], mn, pos);
    }
    debug(mn, pos);
    rep(i, -mn) cout << '(';
    cout << s;
    rep(i, pos-mn) cout << ')';
    cout << endl;
}