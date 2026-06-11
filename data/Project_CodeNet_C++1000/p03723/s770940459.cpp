
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
    
    ll a, b, c;
    cin >> a >> b >> c;

    int ans = 0;
    if(a % 2 != 0 || b % 2 != 0 || c % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }
    if(a == b && b == c) {
        cout << -1 << endl;
        return 0;
    }

    while(1) {
        if(a % 2 != 0 || b % 2 != 0 || c % 2 != 0) {
            break;
        }
        ans++;
        ll x = a, y = b, z = c;
        a = (y + z) / 2;
        b = (x + z) / 2;
        c = (x + y) / 2;
    }

    cout << ans << endl;

    return 0;
}