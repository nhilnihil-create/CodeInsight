#include <bits/stdc++.h>
using namespace std;

using LL = long long;

constexpr int MOD = 1e9+7;
constexpr int N = 200005;

LL powmod (LL a, LL b, LL MOD) {
        LL ans = 1;
        while (b) {
                if (a % 2) ans = ans * a % MOD;
                b /= 2;
                a = a * a % MOD;
        }
        return ans % MOD;
}

LL fac[N], inv[N], fnv[N];

LL comb (LL a, LL b) {
        if (a < b) return 0;
        if (b == 0 || b == a) return 1;
        return fac[a] * fnv[b] % MOD * fnv[a-b] % MOD;
}

int main () {
        fac[0] = inv[0] = fnv[0] = 1;
        fac[1] = inv[1] = fnv[1] = 1;
        for (int i = 2; i < N; ++i) {
                fac[i] = fac[i-1] * i % MOD;
                inv[i] = inv[MOD%i] * (MOD-MOD/i) % MOD;
                fnv[i] = fnv[i-1] * inv[i] % MOD;
        }
        int h, w, a, b; cin >> h >> w >> a >> b;
        LL sum = comb (h+w-2, h-1);
        cerr << "sum = " << sum << endl;
        for (int i = 1; i <= min(100000,a); ++i) {
                // (1,1) -> (b,h-i+1)
                LL cur = comb (b-1+h-i, b-1);
                // (b+1,h-i+1) -> (w,h)
                LL lft = comb (w-b-1+h-h+i-1, w-b-1); 
               // cerr << "(" << b << "," << h-i+1 << ")  ->  (" << w << "," << h << ")" << endl;
               // cerr << "i = " << i << ", cur = " << cur << ", lft = " << lft << endl;
                sum = (sum - cur * lft % MOD) % MOD;
                sum = (sum + MOD) % MOD;
        }
        cout << sum << endl;
        return 0;
}