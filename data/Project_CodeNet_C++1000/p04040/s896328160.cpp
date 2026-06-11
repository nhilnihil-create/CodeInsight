#include <bits/stdc++.h>
using namespace std;

int H, W, A, B;

#define N 200005

int fac[N] = {1, 1}, rfac[N] = {1, 1}, inv[N] = {0, 1};

const int mod = 1e9 + 7;

int C(int n, int m) {
	return 1ll * fac[n] * rfac[n-m] % mod * rfac[m] % mod;
}

void sub(int &a, int b) {
	a -= b;
	if (a < 0) a += mod;
}
int mul(int x, int y) {return 1ll * x * y % mod;}

int main() {
    for (int i = 2; i < N; i ++) {
        inv[i] = 1ll * (mod / i) * (mod - inv[mod%i]) % mod;
        fac[i] = 1ll * fac[i-1] * i % mod;
        rfac[i] = 1ll * rfac[i-1] * inv[i] % mod;
    }
    scanf("%d %d %d %d", &H, &W, &A, &B);
    int ans = C(H+W-2, W-1);
    for (int i = H-A+1; i <= H; i ++) {
        sub(ans, mul(C(i-1+B-1, B-1), C(H-i+W-B-1, H-i)));
    }
    printf("%d\n", ans);
	return 0;
}
