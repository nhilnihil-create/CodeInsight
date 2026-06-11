#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

ll N, T[2000], A[2000];

signed main(){
    cin >> N;
    REP(i, N) cin >> T[i] >> A[i];
    ll t = T[0], a = A[0];
    REP(i, N - 1){
        ll k = max((t + T[i + 1] - 1) / T[i + 1], (a + A[i + 1] - 1) / A[i + 1]);
        t += T[i + 1] * k - t;
        a += A[i + 1] * k - a;
    }
    PRINT(t + a);
    return 0;
}