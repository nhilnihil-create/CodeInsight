#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define ARRAY_LENGTH(array) sizeof(array)/sizeof(*array)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const int INF = 1000100100;

int main() {
    string s;
    cin >> s;

    ll A_minID = INF, Z_maxID = -1;
    REP(i, s.length()) {
        if(s[i] == 'A') {
            chmin(A_minID, i);
        }
        if(s[i] == 'Z') {
            Z_maxID = i;
        }
    }
    ll ans = Z_maxID - A_minID + 1;
    if(ans < 2) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}