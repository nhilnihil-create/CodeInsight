#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD = 1e9+7;


int main() {
    ll n, c, k; cin >> n >> c >> k;

    V<ll> t(n);
    for(int i = 0; i < n; i++) cin >> t[i];
    sort(ALL(t));

    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll cnt = 0;
        ll p = i;
        for(int j = i; j < n; j++){
            if(t[p] <= t[j] && t[j] <= t[p] + k && cnt < c){
                cnt++;
                i = j;
            }else{
                break;
            }
        }
        ans++;
    }
    cout << ans << endl;

    return 0;
}
