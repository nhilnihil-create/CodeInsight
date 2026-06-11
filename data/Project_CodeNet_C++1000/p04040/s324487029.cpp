#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
#include <utility>
#include <numeric>

using namespace std;

const int MOD = 1e9 + 7;

// combination
class Com{
public:
    int n;
    int mod;

    Com(int n, int mod){
        this->n = n;
        this->mod = mod;

        f.resize(n + 1);
        fInv.resize(n + 1);
        inv.resize(n + 1);

        f[0] = f[1] = 1;
        fInv[0] = fInv[1] = 1;
        inv[1] = 1;

        for(int i = 2; i <= n; i++){
            f[i] = (f[i - 1] * i) % mod;
            inv[i] = mod - (inv[mod % i] * (mod / i)) % mod;
            fInv[i] = (fInv[i - 1] * inv[i]) % mod;
        }
    }

    long long query(int n, int k){
        if(n < k){
            return 0;
        }
        if(n < 0 || k < 0){
            return 0;
        }
        return (((f[n] * fInv[k]) % mod) * fInv[n - k]) % mod;
    }
private:
    vector<long long> f, fInv, inv;
};

int main(){

    int H, W, A, B;
    cin >> H >> W >> A >> B;
    Com com(H + W, MOD);

    int ans = 0;
    for(int i = 0; i < H - A; i++){
        int temp1 = com.query(B - 1 + i, i);
        int temp2 = com.query(H + W - i - B - 2, W - B - 1);
        int plus = ((long long)temp1 * temp2) % MOD;
        ans = (ans + plus) % MOD;
    }

    cout << ans << endl;

    return 0;
}