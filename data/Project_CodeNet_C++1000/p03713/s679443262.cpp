#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

pll div2(ll H, ll W){
    ll S1 = H * (W / 2), S2 = H * (W - W / 2);
    ll T1 = (H / 2) * W, T2 = (H - H / 2) * W;
    if(abs(S1 - S2) < abs(T1 - T2)) return pll(S1, S2);
    else return pll(T1, T2);
}

ll div3(ll H, ll W){
    ll S1 = H * (W / 3), S2 = div2(H, W - W / 3).first, S3 = div2(H, W - W / 3).second;
    ll T1 = H * (W / 3 + 1), T2 = div2(H, W - W / 3 - 1).first, T3 = div2(H, W - W / 3 - 1).second;
    return min(max(S1, max(S2, S3)) - min(S1, min(S2, S3)), max(T1, max(T2, T3)) - min(T1, min(T2, T3)));
}

signed main(){
    ll H, W;
    cin >> H >> W;
    PRINT(min(div3(H, W), div3(W, H)));
    return 0;
}