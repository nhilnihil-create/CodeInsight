typedef long long ll;
typedef long double ld;
#include <bits/stdc++.h>
using namespace std;
const ll MOD = 1e9+7;
int main() {
    ll n;
    std::cin >> n;
    vector<ll> x(n);
    ll ans = 1;
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> x[i];
        x[i]--;
        if(x[i]<(i-cnt)*2){
            ans *= i+1-cnt;
            cnt++;
            ans %= MOD;
        }
    }

    for (ll i = 1; i <= n-cnt; i++) {
        ans *= i;
        ans %= MOD;
    }
    
    std::cout << ans << std::endl;
}
