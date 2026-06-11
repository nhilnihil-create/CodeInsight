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
    vector<ll> a(3);
    REP(i, 3) cin >> a[i];

    bool all_ = true;
    REP(i, 3) {
        if(a[i] % 2 == 0) all_ = false;
    }

    if(all_) {
        sort(ALL(a));
        ll tmp1 = 1, tmp2 = 1;
        REP(i, 3) {
            if(i == 2) {
                tmp1 *= a[i] / 2;
                tmp2 *= a[i] / 2 + 1;
            } else {
                tmp1 *= a[i];
                tmp2 *= a[i];
            }
        }
        cout << tmp2 - tmp1 << endl;
    } else {
        cout << "0" << endl;
    }

    return 0;
}