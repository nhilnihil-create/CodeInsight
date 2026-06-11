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
    int n, m, ans = 0;
    cin >> n >> m;
    vector<int> x(m), y(m);
    REP(i, m) {
        cin >> x[i] >> y[i];
        x[i]--, y[i]--;
    }

    vector<bool> isIn(n, false);
    vector<int> ball_num(n, 1);
    isIn[0] = true;

    REP(i, m) {
        if(isIn[x[i]]) isIn[y[i]] = true;
        if(ball_num[x[i]] == 1) {
            isIn[x[i]] = false;
        }
        ball_num[x[i]]--, ball_num[y[i]]++;
    }

    REP(i, n) if(isIn[i]) ans++;

    cout << ans << endl;

    return 0;
}