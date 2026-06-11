#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

ll N, a[100010];

ll solve(bool ev){
    ll ret = 0, sum = 0;
    REP(i, N){
        if(i % 2 == ev){
            ret += max(0LL, 1 - sum - a[i]);
            sum += a[i] + max(0LL, 1 - sum - a[i]);
        }else{
            ret += max(0LL, sum + a[i] + 1);
            sum += a[i] + min(0LL, -1 - sum - a[i]);
        }
    }
    return ret;
}

signed main(){
    cin >> N;
    REP(i, N) cin >> a[i];
    PRINT(min(solve(0), solve(1)));
    return 0;
}