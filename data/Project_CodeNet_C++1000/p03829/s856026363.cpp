#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

ll N, A, B, X[100010];

signed main(){
    cin >> N >> A >> B;
    REP(i, N) cin >> X[i];
    ll ans = 0;
    REP(i, N - 1){
        ans += min((X[i + 1] - X[i]) * A, B);
    }
    PRINT(ans);
    return 0;
}