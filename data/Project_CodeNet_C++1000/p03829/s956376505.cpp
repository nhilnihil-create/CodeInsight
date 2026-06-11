/* 北さん参考 */
#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (ll (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n) for (ll (i) = m ; (i) < (ll)(n) ; ++(i))
#define REP_REV(i, n) for (ll (i) = (ll)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (ll (i) = (ll)(n) - 1 ; (i) >= m ; --(i))

#define INF 2e9
#define INF_LL 1LL<<60
#define ll long long

typedef pair<ll, ll> P;

int main(){
    ll n, a, b;
    ll ans = 0;
    cin >> n >> a >> b;
    vector<int> x(n);
    REP(i, n) cin >> x[i];

    REPN(i, 1, n) {
        if((x[i] - x[i-1]) * a < b) {
            ans += (x[i] - x[i-1]) * a;
        } else {
            ans += b;
        }
    }

    cout << ans << endl;

    return 0;
}
