
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
    ll n, a, b;
    cin >> n >> a >> b;

    if(a > b) {
        cout << 0 << endl;
        return 0;
    }

    if(n == 1) {
        if(a == b) cout << 1 << endl;
        else cout << 0 << endl;
        return 0;
    }

    ll shita = a * (n-1) + b;
    ll ue = b * (n-1) + a;

    cout << ue - shita + 1 << endl;

    return 0;
}