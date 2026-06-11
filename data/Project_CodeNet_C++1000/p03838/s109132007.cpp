
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
    int x, y;
    cin >> x >> y;
    if(x < y) {
        int ans = y-x;
        if(x <= 0 || y >= 0) {
            int tmp = 1 + abs(x+y);
            ans = min(y-x, tmp);
        }
        cout << ans << endl;
    } else if(x > y){
        int ans;
        if(y <= 0 && x >= 0) {
            ans = 1 + abs(x+y);
        } else {
            ans = 2 + abs(x-y);
        }
        cout << ans << endl;
    } else {
        cout << "0" << endl;
    }

    return 0;
}