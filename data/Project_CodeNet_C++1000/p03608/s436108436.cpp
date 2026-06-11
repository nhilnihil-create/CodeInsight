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
    ll n, m, r;
    cin >> n >> m >> r;
    vector<int> visit(r);
    REP(i, r) {
        cin >> visit[i];
        visit[i]--;
    }
    sort(ALL(visit));

    ll table[n][n];
    REP(i, n) REP(j, n) {
        table[i][j] = INF_LL;
        if(i == j) table[i][j] = 0;
    }

    REP(i, m) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        table[a][b] = min(table[a][b], c);
        table[b][a] = min(table[b][a], c);
    }
    REP(k, n) REP(i, n) REP(j, n) table[i][j] = min(table[i][j], table[i][k] + table[k][j]);

    ll ans = INF_LL;

    do {
        ll tmp = 0;
        REP(i, r-1) {
            tmp += table[visit[i]][visit[i+1]];
        }
        ans = min(ans, tmp);
    } while (next_permutation(ALL(visit)));

    cout << ans << endl;

    return 0;
}