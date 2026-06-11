/* 北さん参考 */
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
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    int ans[h][w];

    int idx = 1;
    int kosu = 0;

    REP(i, h) REP(j, w) {
        if(i % 2 == 0) {
            ans[i][w-j-1] = idx;
        } else {
            ans[i][j] = idx;
        }
        kosu++;
        if(a[idx-1] == kosu) {
            kosu = 0, idx++;
        }
    }

    REP(i, h) {
        REP(j, w) cout << ans[i][j] << " ";
        cout << endl;
    }

    return 0;
}
