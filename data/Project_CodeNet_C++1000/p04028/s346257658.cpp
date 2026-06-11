#include<iostream>
#include<cstring>
using  namespace  std;
const  int N = 5005, mod = 1e9 + 7;
int n, f[N][N], m; char s[N];
int  main() {
	scanf("%d%s", &n, s + 1); m = strlen(s + 1);
	f[0][0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++) {
			if (j) f[i + 1][j - 1] = (f[i + 1][j - 1] + f[i][j]) % mod;
			else f[i + 1][j] = (f[i + 1][j] + f[i][j]) % mod;
			f[i + 1][j + 1] = (f[i + 1][j + 1] + 1ll * f[i][j] * 2) % mod;
		}
	for (int i = 1; i <= m; i++) f[n][m] = 1ll * f[n][m] * 500000004 % mod;
	printf("%d \n", f[n][m]);
	return  0;
}