#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int H, W, A, B;
int mod = 1e9 + 7;

int power(int a, int n){
    if (n == 0) {
        return 1;
    } else if (n % 2 == 0) {
        int b = power(a, n / 2);
        return 1ll * b * b % mod;
    } else {
        return 1ll * a * power(a, n - 1) % mod;
    }
}

int inverse(int a) {
    if (a == 1) {
        return 1;
    }
    return power(a, mod - 2);
}

int main() {
    cin >> H >> W >> A >> B;
    int C = min(A, B), M = max(H, W);
    vector<int> fact(H + W, 1), fact_inv(M, 1);
    for (int i = 1; i < H + W; i++) {
        fact[i] = 1ll * fact[i - 1] * i % mod;
        if (i < M) {
            fact_inv[i] = inverse(fact[i]);
        }
    }
    int all = 1ll * fact[H + W - 2] * fact_inv[H - 1] % mod * fact_inv[W - 1] % mod;
    
    int block = 0;
    for (int i = 0; i < C; i++) { //(下からA - i, 左からB - i)番目のブロックを通る経路
        block += 1ll * fact[H - A + B - 1] * fact_inv[H - A + i] % mod * fact_inv[B - i - 1] % mod
                * fact[W - B + A - 1] % mod * fact_inv[W - B + i] % mod * fact_inv[A - i - 1] % mod;
        block %= mod;
    }
    cout << (all - block + mod) % mod << endl;
}