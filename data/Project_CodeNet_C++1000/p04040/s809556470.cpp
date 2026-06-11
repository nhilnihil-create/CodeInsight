#include <bits/stdc++.h>
#include<ext/pb_ds/hash_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#define N 200005
using namespace __gnu_pbds;
const int mod = 1e9 + 7;
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
LL z = 1;
int read(){
	int x, f = 1;
	char ch;
	while(ch = getchar(), ch < '0' || ch > '9') if(ch == '-') f = -1;
	x = ch - '0';
	while(ch = getchar(), ch >= '0' && ch <= '9') x = x * 10 + ch - 48;
	return x * f;
}
int ksm(int a, int b, int p){
	int s = 1;
	while(b){
		if(b & 1) s = z * s * a % p;
		a = z * a * a % p;
		b >>= 1;
	}
	return s;
}

int maxn = N - 5, fac[N], inv[N];
int C(int n, int m){
	return z * fac[n] * inv[m] % mod * inv[n - m] % mod; 
}
int main(){
	int i, j, a, b, n, m, c, d, ans, sum = 0;
	for(fac[0] = i = 1; i <= maxn; i++) fac[i] = z * fac[i - 1] * i % mod;
	inv[maxn] = ksm(fac[maxn], mod - 2, mod);
	for(i = maxn - 1; i >= 0; i--) inv[i] = z * inv[i + 1] * (i + 1) % mod;
	scanf("%d%d%d%d", &n, &m, &c, &d);
	ans = C(n + m - 2, n - 1);
	for(i = 1; i <= d; i++){
		a = n - c;
		b = i - 1;
		j = C(a + b, a);
		j = (j - sum) % mod;
		sum = (sum + j) % mod;
		j = z * j * C(c - 1 + m - i, c - 1) % mod;
		//printf("%d %d\n", i, j);
		ans = (ans - j) % mod;
	}
	ans = (ans + mod) % mod;
	printf("%d", ans);
	return 0;
}
