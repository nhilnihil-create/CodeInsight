#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

signed main(){
    ll N, ans = LONG_LONG_MAX;
    cin >> N;
    for(ll A = 1; A * A <= N; A++){
        if(N % A != 0) continue;
        ll B = N / A;
        ans = min(ans, max((ll)log10(A) + 1, (ll)log10(B) + 1));
    }
    PRINT(ans);
    return 0;
}