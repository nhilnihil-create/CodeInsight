#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
template<typename T> auto compare = [](T x, T y) -> bool{return (x < y);};
const int MOD = 1000000007;

ll N, a[100010];

ll solve(ll s){
    ll sum = a[0] + s, ans = abs(s);
    if(sum == 0) return LONG_LONG_MAX;
    FOR(i, 1, N){
        if(sum * (sum + a[i]) < 0){
            sum += a[i];
        }else{
            if(sum < 0){
                ans += 1 - (sum + a[i]);
                sum = 1;
            }else if(sum > 0){
                ans += 1 + (sum + a[i]);
                sum = -1;
            }
        }
    }
    return ans;
}

signed main(){
    cin >> N;
    REP(i, N) cin >> a[i];
    if(a[0] > 0){
        PRINT(min(solve(0), solve(-1 - a[0])));
    }else if(a[0] < 0){
        PRINT(min(solve(0), solve(1 - a[0])));
    }else{
        PRINT(min(solve(1), solve(-1)));
    }
    return 0;
}  