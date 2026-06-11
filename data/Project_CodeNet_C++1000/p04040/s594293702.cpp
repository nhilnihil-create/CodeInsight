#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
const int MAX = 510000;
const int MOD = 1000000007;
typedef long long ll;

ll fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

ll COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
    int h,w,a,b;
    ll ans = 1;
    cin >> h >> w >> a >> b;
    COMinit();
    for(int i = b;i < w;i++){
        ll tmp = COM(h-a-1+i,i)*COM(a-2+w-i,w-1-i)%MOD;
        ans += tmp;
        ans %= MOD;
    }
    cout << ans-1 << endl;
}
