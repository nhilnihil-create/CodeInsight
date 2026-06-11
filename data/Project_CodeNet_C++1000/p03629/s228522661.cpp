#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
#define REP(i, n) FOR(i, 1, ll(n) + 1)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

constexpr ll mod = 1e9 + 7;

template <typename T> inline bool chmax(T &a, const T b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> inline bool chmin(T &a, const T b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    string s;
    cin >> s;

    int n = s.size();
    vector<int> dp(n + 2, 1 << 30), a(n + 1), ret(n + 1), last(26, n + 1);
    vector<vector<int>> nxt(n + 1, vector<int>(26));

    REP(i, n) a[i] = s[i - 1] - 'a';
    dp[n + 1] = 0;

    for(int i = n; i >= 0; i--) {
        rep(j, 26) {
            nxt[i][j] = last[j];
            if(chmin(dp[i], dp[last[j]] + 1)) ret[i] = j;
        }
        last[a[i]] = i;
    }

    int id = 0;
    while(id <= n) {
        cout << char(ret[id] + 'a');
        id = nxt[id][ret[id]];
    }
}