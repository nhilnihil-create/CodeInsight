#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (ll (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n) for (ll (i) = m ; (i) < (ll)(n) ; ++(i))
#define REP_REV(i, n) for (ll (i) = (ll)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (ll (i) = (ll)(n) - 1 ; (i) >= m ; --(i))

#define INF 2e9
#define INF_LL 1LL<<60
#define ll long long

typedef pair<int, int> P;

int main() {
    int n;
    ll ans = 0;
    cin >> n;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    ans += a[0] - 1;
    int point = 2;

    REPN(i, 1, n) {
        if (a[i] == point) {
            point++;
            continue;
        }
        if (a[i] < point) continue;
        if(a[i] % point == 0) {
            ans += a[i] / point - 1;
        } else {
            ans += a[i] / point;
        }
    }

    cout << ans << endl;

    return 0;
}