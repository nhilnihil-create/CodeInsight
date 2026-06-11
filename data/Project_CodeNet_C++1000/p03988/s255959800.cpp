#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;

template <class T> inline bool chmax(T &a, const T &b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <class T> inline bool chmin(T &a, const T &b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

int n, num[100], mx;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    rep(i, n) {
        int a;
        cin >> a;
        chmax(mx, a);
        num[a]++;
    }
    bool ok = num[mx / 2 + mx % 2] - 1 == mx % 2;
    FOR(i, mx / 2 + 1, mx + 1) ok = ok && num[i] > 1;
    rep(i, mx / 2 + mx % 2) ok = ok && !num[i];
    cout << (ok ? "Possible" : "Impossible");
}