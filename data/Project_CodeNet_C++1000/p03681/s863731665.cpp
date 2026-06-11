#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD = 1e9+7;

ll factorial(ll n) {
    ll ans = 1;
    for(ll i = 1; i <= n; i++){
        ans *= i;
        ans %= MOD;
    }
    return ans % MOD;
}

int main() {
    ll n,m; cin >> n >>m;
    if(abs(n - m) > 1){
        cout << 0 << endl;
        return 0;
    }

    if(n == m){
        cout << factorial(n) * factorial(m) % MOD * 2 % MOD << endl;
    }else{
        cout << factorial(n) * factorial(m) % MOD << endl;
    }



    return 0;
}
