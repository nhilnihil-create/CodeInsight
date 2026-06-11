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
    int n, c, k;
    cin >> n >> c >> k;
    vector<int> t(n);
    REP(i, n) cin >> t[i];
    sort(ALL(t));

    int saisyo = t[0], jokyaku = 1, ans = 0;
    REPN(i, 1, n) {
        if(t[i] - saisyo > k) {
            ans++;
            saisyo = t[i];
            jokyaku = 1;
        } else {
            if(jokyaku < c) {
                jokyaku++;
            } else {
                ans++;
                jokyaku = 1;
                saisyo = t[i];
            }
        }
    }

    ans++;

    cout << ans << endl;

    return 0;
}