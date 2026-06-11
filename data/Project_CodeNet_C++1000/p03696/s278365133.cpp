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
    string S; cin >> S;
    vector<int> a(n, 0);
    rep(i, n) {
        if (S[i]=='(') a[i]=1;
        else a[i]=-1;
    }
    vector<int> s(n+1, 0);
    rep(i, n) s[i+1] = s[i]+a[i];
    debug(s);
    int base = 0;
    string t;
    rep(i, n+1) {
        if (s[i]+base<0) {
            int m = abs(s[i]+base);
            debug(i, m, base);
            rep(j, m) {
                t+='(';
                base++;
            }
        }
    }
    string u;
    debug(s.back(), base);
    if (s.back()+base>0) {
        rep(i, s.back()+base) u+=')';
    }
    string ans = t + S + u;
    cout << ans << endl;
}