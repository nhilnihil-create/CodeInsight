#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

signed main(){
    string S;
    cin >> S;
    ll ans = 0;
    REP(i, S.length()){
        if(i < (S.length()+ 1) / 2) ans += (S[i] == 'g' ? 0 : -1);
        else ans += (S[i] == 'g' ? 1 : 0);
    }
    PRINT(ans);
    return 0;
}