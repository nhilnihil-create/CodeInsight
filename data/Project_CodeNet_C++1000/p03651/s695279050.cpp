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

ll gcd(ll a, ll b){
    ll tmp;
    if(a<b){
        tmp = a;
        a = b;
        b = tmp;
    }

    ll r = a%b;
    while(r!=0){
        a = b;
        b = r;
        r = a % b;
    }

    return b;
}

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    REP(i, n) cin >> a[i];

    bool nukeru = true;
    REP(i, n) {
        if(a[i] >= k) nukeru = false;
    }

    if(nukeru) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    int gcd_ = a[0];
    REP(i, n-1) {
        gcd_ = gcd(gcd_, a[i+1]);
    }

    REP(i, n) {
        if((k-a[i]) % gcd_ == 0) {
            cout << "POSSIBLE" << endl;
            return 0;
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}