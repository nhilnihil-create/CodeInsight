#include <bits/stdc++.h>

using namespace std;

const int P = 1e9 + 7;
const int N = 2005;

long long frac[N * N], inv_frac[N * N], f[N][N], Sf[N][N];

inline long long ksm(long long base, long long x) {
    long long res = 1;
    while(x) {
        if(x & 1) res *= base, res %= P;
        x >>= 1, base *= base, base %= P;
    }
    return res;
}

inline long long C(int x, int y) {
    if(x >= y && y >= 0) {
        return frac[x] * inv_frac[y] % P * inv_frac[x - y] % P;
    }
    return 0;
}

inline void init() {
    int n, k;
    cin >> n >> k;
    if(k == 1) {
        printf("1\n");
        return ;
    }
    frac[0] = 1, inv_frac[0] = 1;
    for(int i = 1; i <= n * k; i++) frac[i] = (frac[i - 1] * i) % P, inv_frac[i] = ksm(frac[i], P - 2);


    Sf[1][0] = Sf[1][1] = f[1][1] = 1;

    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= i; j++) f[i][j] = C(i * k - j - 1, k - 2) * Sf[i - 1][j - 1] % P;
        for(int j = i; j >= 0; j--) Sf[i][j] = (Sf[i][j + 1] + f[i][j]) % P;
    }
/*
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            printf("%lld ", f[i][j]);
        }
        printf("\n");
    }
    printf("\n");
*/
    cout << Sf[n][1] * frac[n] % P << endl;
}

int main() {
    init();
    return 0;
}