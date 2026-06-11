#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
#include <cmath>
#include <numeric>

using namespace std;
long long MOD = 1000000007;
const int MAX = 200001;
long long fac[MAX];
long long finv[MAX];
long long inv[MAX];

void comb_init() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long comb(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
    int H;
    int W;
    int A;
    int B;
    cin >> H >> W >> A >> B;

    comb_init();
    long long ans = 0;
    for(int i = 0; i < H - A; i++){
        ans = (ans + (comb(i + B - 1, i) * comb(W - B + H - i - 2, W - B - 1)) % MOD) % MOD;
    }

    cout << ans << endl;
    
    return 0;
}
