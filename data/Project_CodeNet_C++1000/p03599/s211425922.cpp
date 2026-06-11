#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

ll A, B, C, D, E, F;

signed main(){
    cin >> A >> B >> C >> D >> E >> F;
    ll w = F, s = 0;
    for(ll a = 0; a <= F; a += 100 * A){
        for(ll b = 0; a + b <= F; b += 100 * B){
            if(a + b == 0) continue;
            for(ll c = 0; a + b + c <= F; c += C){
                for(ll d = 0; a + b + c + d <= F; d += D){
                    if(100 * (c + d) > E * (a + b)) continue;
                    if(s * (a + b + c + d) <= (c + d) * (w + s)){
                        w = a + b;
                        s = c + d;
                    }
                }
            }
        }
    }
    cout << w + s << " " << s << endl;
    return 0;
}