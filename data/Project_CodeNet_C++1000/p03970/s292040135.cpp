#include <bits/stdc++.h>

#define debug(x) cerr << #x << ": " << x << endl
#define debugArray(x, n)                                                       \
    for(long long hoge = 0; (hoge) < (n); ++(hoge))                            \
    cerr << #x << "[" << hoge << "]: " << x[hoge] << endl
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
const ll INF = LLONG_MAX / 2;
const ll MOD = 1e9 + 7;

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    string T = "CODEFESTIVAL2016";
    ll ans = 0;
    for(int i = 0; i < 16; i++) {
        ans += S[i] != T[i];
    }
    cout << ans << endl;
    return 0;
}
