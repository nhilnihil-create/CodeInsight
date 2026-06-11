#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (ll (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n) for (ll (i) = m ; (i) < (ll)(n) ; ++(i))
#define REP_REV(i, n) for (ll (i) = (ll)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (ll (i) = (ll)(n) - 1 ; (i) >= m ; --(i))

#define INF 2e9
#define INF_LL 1LL<<60
#define ll long long

const int MAX = 2000005;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    int kisu = 0, gusu = 0;
    
    REP(i, n) {
        cin >> a[i];
        if(a[i] % 2 == 0) gusu++;
        else kisu++;
    }

    if(kisu % 2 != 0) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    return 0;

    return 0;
}