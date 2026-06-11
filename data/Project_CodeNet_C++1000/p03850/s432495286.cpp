#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

inline int gi()
{
	char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	int sum = 0;
	while ('0' <= c && c <= '9') sum = sum * 10 + c - 48, c = getchar();
	return sum;
}

inline int gc()
{
	char c = getchar();
	while (c != '-' && c != '+') c = getchar();
	return c == '+' ? 1 : -1;
}

inline void chkmax(ll &a, ll b) {if (a < b) a = b;}

int n, a[maxn], b[maxn], pw[3];
ll f[maxn][3];

int main()
{
	n = gi();
	a[1] = gi(); b[1] = 1;
	for (int i = 2; i <= n; ++i) b[i] = gc(), a[i] = gi();

	memset(f, -63, sizeof(f));
	f[1][0] = a[1];
	pw[0] = pw[2] = 1; pw[1] = -1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= 2; ++j)
			if (f[i][j] > -1e18) {
				chkmax(f[i + 1][j], f[i][j] + a[i + 1] * b[i + 1] * pw[j]);
				if (j) chkmax(f[i + 1][j - 1], f[i][j] + a[i + 1] * b[i + 1] * pw[j - 1]);
				if (b[i + 1] < 0 && j < 2) chkmax(f[i + 1][j + 1], f[i][j] + a[i + 1] * b[i + 1] * pw[j]);
				if (b[i + 1] < 0 && j) chkmax(f[i + 1][j], f[i][j] + a[i + 1] * b[i + 1] * pw[j - 1]);
			}
	}

	printf("%lld\n", max(f[n][0], max(f[n][1], f[n][2])));
	
	return 0;
}
