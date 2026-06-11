
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

//Combination Table
ll C[51][51]; /* C[n][k] -> nCk */

void comb_table(int N) {
    REP(i, N+1) REP(j, i+1) {
        if(j == 0 || j == i) {
            C[i][j] = 1LL;
        } else {
            C[i][j] = (C[i-1][j-1] + C[i-1][j]);
            //cout << C[i][j] << endl;
        }
    }
}

int main() {
    ll n, p;
    cin >> n >> p;
    vector<ll> a(n);
    ll gusu, kisu = 0;
    gusu = 0;

    REP(i, n) {
        cin >> a[i];
        if(a[i] % 2 == 0) {
            gusu++;
        } else {
            kisu++;
        }
    }

    ll tori = 1;
    REPN(i, 1, gusu+1) {
        tori *= 2;
    }
    comb_table(50);
    ll ans = 0;

    if(p % 2 == 1) {
        /* 奇数を奇数個 */
        for(int i = 1; i <= kisu ; i += 2) {
            ll tmp = C[kisu][i];
            //cout << kisu << " " << i << " " << tmp << endl;
            tmp *= tori;
            ans += tmp;
        }
    } else {
        /* 奇数を偶数個 */
        for(int i = 0; i <= kisu ; i += 2) {
            ll tmp = C[kisu][i];
            //cout << kisu << " " << i << " " << tmp << endl;
            tmp *= tori;
            ans += tmp;            
        }
    }

    cout << ans << endl;

    return 0;
}