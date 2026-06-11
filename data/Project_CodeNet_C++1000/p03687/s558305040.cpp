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
const int INF = 1001001001;
const int MOD = 1000000007;
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

    string s; cin >> s;
    set<char> chars;
    rep(k, sz(s)) chars.insert(s[k]);
    if (chars.size()==1) {
        cout << 0 << endl;
        return 0;
    }
    int ans = INF;
    int n = sz(s);
    rep(i, 26) {
        char c = 'a'+i;
        if (!chars.count(c)) continue;
        int cnt = 0;
        string t = s;
        debug(t);
        rep(j, n/2+1) {
            int del; 
            rep(k, sz(t)) {
                if ((k<sz(t)-1&&t[k]!=c&&t[k+1]!=c) || k==sz(t)-1) del = k;
                if (k<sz(t)-1 && t[k+1]==c) t[k] = c;
            }
            t.erase(t.begin()+del);
            debug(c, t);
            set<char> st;
            rep(k, sz(t)) st.insert(t[k]);
            cnt++;
            if (st.size()==1) break;
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
}