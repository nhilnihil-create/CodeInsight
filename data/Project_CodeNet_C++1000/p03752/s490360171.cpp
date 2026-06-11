#include <bits/stdc++.h>
#include <bitset>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;


int main() {
    int n, k; cin >> n >> k;
    V<ll> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    ll ans = 1LL << 60;
    for(int bit = 0; bit < (1 << n); bit++){
        // 1がk個立っている場合のみ
        if(__builtin_popcount(bit) != k) continue;
        ll s = v[0] - 1, sum = 0;
        for(int i = 0; i < n; i++){
            if(bit & (1 << i)){
                if(v[i] <= s){
                    s++;
                    sum += s - v[i];
                }else{
                    s = v[i];
                }
            }else{
                s = max(s, v[i]);
            }
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;

    return 0;
}
