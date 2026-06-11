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
    vector<P> tmp(n);
    REP(i, n) {
        cin >> a[i];
        tmp[i].first = a[i], tmp[i].second = i;
    }
    sort(ALL(tmp));
    REP(i, n) a[tmp[i].second] = i+1;

    int ans = 0;
    REP(i, n) if(i % 2 == 0) if(a[i] % 2 != 1) ans++;

    cout << ans << endl;

    return 0;
}