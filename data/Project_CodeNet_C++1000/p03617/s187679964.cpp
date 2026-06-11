#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (ll (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n) for (ll (i) = m ; (i) < (ll)(n) ; ++(i))
#define REP_REV(i, n) for (ll (i) = (ll)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (ll (i) = (ll)(n) - 1 ; (i) >= m ; --(i))

#define INF 1e9 + 1
#define INF_LL 1LL<<60
#define ll long long
#define ALL(x)          (x).begin(),(x).end()

#define MAX_V 105

#define MAX_N 100
#define MAX_M 100

int main(){
    ll q, h, s, d, n;
    cin >> q >> h >> s >> d >> n;
    q *= 4, h *= 2;

    vector<int> a(3);
    a[0] = q, a[1] = h, a[2] = s;
    sort(ALL(a));

    if(a[0] * 2 > d) {
        int tmp = n / 2;
        int tmp2 = n % 2;
        cout << d * tmp + tmp2 * a[0] << endl;
    } else {
        cout << a[0] * n << endl;
    }

    return 0;
}