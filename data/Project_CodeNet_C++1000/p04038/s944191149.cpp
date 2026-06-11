#include <bits/stdc++.h>
#define maxn 2086

using namespace std;

const int p = 1e9 + 7;

inline int fpow(int x, int y){
	int ans = 1;
	while(y){
		if(y & 1) ans = 1ll * ans * x % p;
		x = 1ll * x * x % p, y >>= 1;
	}
	return ans;
}

int sum[maxn * maxn], inv[maxn * maxn];

inline int C(int n, int m){
	return 1ll * sum[n] * inv[m] % p * inv[n - m] % p;
}

int n, k;
int f[maxn][maxn];

int main(){
	scanf("%d%d", &n, &k);
	if(k == 1) return printf("1"), 0;
	sum[0] = 1;for(int i = 1;i <= n * k;i++) sum[i] = 1ll * sum[i - 1] * i % p;
	inv[n * k] = fpow(sum[n * k], p - 2);
	for(int i = n * k - 1;~i;i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % p;
	f[0][0] = 1;
	for(int i = 1;i <= n;i++){
		for(int j = 0;j <= i;j++){
			f[i][j] = f[i - 1][j];
			f[i][j] = (f[i][j] + 1ll * f[i][j - 1] * (n - j + 1) % p * C(n * k - i - (j - 1) * (k - 1) - 1, k - 2)) % p;
		}
	}
	printf("%d", f[n][n]);
}