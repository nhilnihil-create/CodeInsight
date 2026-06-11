#include <bits/stdc++.h>

#define rep(i, N) for (int i = 0; i < N; i++)
#define rep1(i, N) for (ll i = 1; i <= N; i++)
#define repr(i, N) for (ll i = N-1; i >= 0; i--)
#define repr1(i, N) for (ll i = N; i > 0; i--)

#define MODNUM 1000000007

using ll = long long;
using namespace std;

int main(){
    string S;
    cin >> S;

    ll ans = 0;
    int N = (int)S.size()-1;

    //R個の全探索(2^R通り)
    for (int bit = 0; bit < (1 << N); bit++) {
        int tmp = -1;
        for (int i = 0; i < N; i++) {
            //i番目のビットが立っていた時の処理
            if (bit & (1<<i)) {
                string subS = S.substr(tmp+1, i-tmp);
                ll t = 0;
                rep(j,subS.size()) {
                    t += (subS[j] - '0');
                    if(j != (int)subS.size()-1) t *=10;
                }
                ans += t;
                tmp = i;
            }
        }
        
        string subS = S.substr(tmp+1);
        ll t = 0;
        rep(j,subS.size()) {
            t += (subS[j] - '0');
            if(j != (int)subS.size()-1) t *=10;
        }
        ans += t;
    }
    
    cout << ans << endl;
    return 0;
}
