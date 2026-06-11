
#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (ll (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n) for (ll (i) = m ; (i) < (ll)(n) ; ++(i))
#define REP_REV(i, n) for (ll (i) = (ll)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (ll (i) = (ll)(n) - 1 ; (i) >= m ; --(i))

#define INF             2e9
#define INF_LL          1LL<<60
#define ll              long long
#define Ceil(x, n)      (((((x))+((n)-1))/n))
#define CeilN(x, n)     (((((x))+((n)-1))/n)*n)
#define FloorN(x, n)    ((x)-(x)%(n))
#define ALL(x)          (x).begin(),(x).end()
typedef pair<ll, ll>    P;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    REP(i, n) cin >> a[i];
    sort(ALL(a));
    vector<ll> ruiseki(n+1, 0);
    REP(i, n) ruiseki[i+1] = ruiseki[i] + a[i];

    ll ans = 1;
    REP_REV(i, n-1) {
        if(ruiseki[i+1] * 2 >= a[i+1]) {
            ans++;
        } else {
            break;
        }
    }

    cout << ans << endl;
    return 0;
}