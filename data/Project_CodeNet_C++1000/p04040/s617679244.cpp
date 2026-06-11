#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 2e5 + 100, p = 1e9 + 7;

typedef long long LL;
LL inv[N], fac[N], f[N][2];

LL qmi(LL a, int b) {
	LL res = 1;
	for(; b; b >>= 1) {
		if( b & 1)
			res = res * a % p;
		a = a * a % p; 
	}
	return res;
}

void Com()
{
	fac[0] = inv[0] = 1;
	for(int i = 1; i <= 2e5; i ++) {
		fac[i] = fac[i - 1] * i % p;
		inv[i] = inv[i - 1] * qmi(i, p - 2) % p;
	//	printf("int[%d] = %lld\n", i, inv[i]);
	}
}

int main()
{
	int n, m, x, y;
	scanf("%d%d%d%d", &n, &m, &x, &y);
	Com();
	for(int i = y + 1; i <= m; i ++) {
		int a = n - x + i - 2, b = n - x - 1;
		f[i][0] = fac[a] * inv[b] % p * inv[a - b] % p;
	//	printf("%lld ", f[i][0]);
	}
//	puts("");
	LL res = 0;
	for(int i = y + 1; i <= m; i ++) {
		int a = x + m - i + 1 - 2, b = x - 1;
		LL t =  fac[a] * inv[b] % p * inv[a - b] % p;
		res = (res + t * f[i][0]) % p;
	//	printf("%lld\n", t);
	} 
	printf("%lld\n", res);
	return 0;
}