#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const ll MOD = 1e9 + 7;

ll factorial(ll n) {
    ll ans = 1;
    for(ll i = 1; i <= n; i++){
        ans *= i;
        ans %= MOD;
    }
    return ans % MOD;
}

int main() {
    ll n, m; cin >> n >> m;

    if(n == m){
        cout << factorial(n) * factorial(m) % MOD * 2 % MOD << endl;
    }else if(n - 1 == m || m - 1 == n){
        cout << factorial(n) * factorial(m) % MOD << endl;
    }else{
        cout << 0 << endl;
    }
}
