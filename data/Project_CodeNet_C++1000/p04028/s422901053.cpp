#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<cmath>
#include<algorithm>
#define N 5005
#define MOD 1000000007
using namespace std;
int n,len;
char s[N];
long long dy[N][N];
long long ex_func(long long x, long long ex) {
	long long ret=1;
	while (ex > 0) {
		if (ex % 2 == 1) {
			ret *= x; ret %= MOD;
		}
		x *= x; x %= MOD;
		ex /= 2;
	}
	return ret;
}
int main() {
	scanf("%d", &n);
	scanf(" %s", s);
	len = strlen(s);
	dy[0][0] = 1;
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 0; j <= n; j++) {
			if (j == 0) dy[i][j] = dy[i - 1][j] + dy[i - 1][j + 1];
			else dy[i][j] = dy[i - 1][j - 1] * 2 + dy[i - 1][j + 1];
			dy[i][j] %= MOD;
		}
	}
	long long div = 1;
	for (i = 1; i <= len; i++) {
		div *= 2; div %= MOD;
	}
	printf("%lld", dy[n][len] * ex_func(div, MOD - 2)%MOD);
	return 0;
}