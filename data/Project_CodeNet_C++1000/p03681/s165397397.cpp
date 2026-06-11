#include <bits/stdc++.h>
using namespace std;
constexpr int64_t MOD = 1e9 + 7;

vector<int64_t> fac(1e6);

int64_t modpow(int64_t x, int64_t n){
    int64_t res = 1;
    for(int64_t i = n; i > 0; i >>= 1){
        if(i & 1) res = res * x % MOD;
        x = x * x % MOD;
    }
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;

    fac[0] = 1;
    for(int64_t i = 0; i + 1 < fac.size(); i++){
        fac[i+1] = fac[i] * (i + 1) % MOD;
    }

    int64_t ans = 0;
    if(n == m){
        ans = modpow(fac[n], 2) * 2 % MOD;
    }else if(abs(n - m) == 1){
        ans = fac[n] * fac[m] % MOD;
    }
    cout << ans << endl;
    return 0;
}