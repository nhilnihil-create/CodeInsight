#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()

int main(){
    ll n, m;
    cin >> n >> m;
    if(abs(n - m) > 1){
        cout << 0 << endl;
        return 0;
    }
    ll mx = max(n, m);
    ll my = min(n, m);
    ll ans = 1;
    constexpr ll mod = 1e9 + 7;
    rep(i, 1, mx+1){
        ans *= i;
        ans %= mod;
    }
    rep(i, 1, my+1){
        ans *= i;
        ans %= mod;
    }
    if(mx - my == 1) cout << ans << endl;
    else cout << (2 * ans) % mod << endl;
    return 0;
}