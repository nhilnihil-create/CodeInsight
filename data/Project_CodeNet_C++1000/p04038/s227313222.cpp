#include<bits/stdc++.h>
#define LL long long
#define LD long double
#define DD double
#define inf 1000000000
#define eps 0.000001
#define maxn 2000
#define mod 1000000007
using namespace std;

int n, k, inv[maxn * maxn + 1], fac[maxn * maxn + 1];
int f[maxn + 1][maxn + 1];

void read(int &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int c(int x, int y){
	if(x < y) return 0;
	return 1ll * fac[x] * inv[y] % mod * inv[x - y] % mod;
}

int main(){
	read(n); read(k);
	if(k == 1){
		puts("1");
		return 0;
	}
	inv[0] = inv[1] = fac[0] = fac[1] = 1;
	for(int i = 2; i <= n * k; ++i) inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
	for(int i = 2; i <= n * k; ++i){
		inv[i] = 1ll * inv[i - 1] * inv[i] % mod;
		fac[i] = 1ll * fac[i - 1] * i % mod;
	}
	f[0][0] = 1;
	for(int i = 1; i <= n; ++i){
		for(int j = 0; j <= i; ++j){
			if(j) f[i][j] = (1ll * f[i][j] + f[i][j - 1]) % mod;
			f[i][j] = (1ll * f[i][j] + 1ll * f[i - 1][j] * (n - (i - 1)) % mod * c((i - 1) * (k - 1) + j + k - 2, k - 2) % mod) % mod;
		}
	}
//	cout << c() << endl;
	printf("%d\n", f[n][n]);
	return 0;
}

