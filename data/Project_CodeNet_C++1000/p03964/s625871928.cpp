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
    ll n;
    cin >> n;
    ll aoki, takahashi;
    cin >> takahashi >> aoki;

    REPN(loop, 1, n) {
        ll a, t;
        cin >> t >> a;
        ll nt, na;
        if(takahashi % t == 0) {
            nt = takahashi / t;
        } else {
            nt = takahashi / t + 1;
        }
        if(aoki % a == 0) {
            na = aoki / a;
        } else {
            na = aoki / a + 1;
        }

        na = max(na, nt);
        
        takahashi = na * t;
        aoki = na * a;
    }

    cout << takahashi + aoki << endl;

    return 0;
}
