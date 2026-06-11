#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

signed main(){
    ll n,x;
    cin >> n >> x;
    ll ans = n;
    ll mx = max(x, n - x), mn = min(x, n - x);
    while(mx % mn != 0){
        ans += (mx / mn) * 2 * mn;
        ll k = mx % mn;
        mx = mn;
        mn = k;
    }
    ans += ((mx / mn) * 2 - 1) * mn;
    cout << ans << endl;
    return 0;
}