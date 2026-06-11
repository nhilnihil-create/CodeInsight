#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;

using ll = long long;
int A[N], n;
ll f[N][3];
bool o[N];
char s;

int pd (int a, bool o) { return o ? a : -a; }

int main () {
	scanf("%d", &n);
	for (int i = o[1] = 1; i <= n; ++i) {
		if (i > 1) scanf("%s", &s), o[i] = s == '+' ? 1 : 0;
		scanf("%d", &A[i]);
	}
	f[0][1] = f[0][2] = -0x3f3f3f3f3f3f3f3f;
	for (int i = 1; i <= n; ++i) {
		f[i][2] = f[i - 1][2];
		for (int j = 0; j < 2; ++j) f[i][j] = max(f[i - 1][j], f[i - 1][j + 1]);
		for (int j = 0; j < 3; ++j) f[i][j] += ((o[i] ^ (j & 1)) ? A[i] : -A[i]);
		if (!o[i]) for (int j = 2; j; --j) f[i][j] = max(f[i][j - 1], f[i][j]);
	}
	printf("%lld\n", max(f[n][0], max(f[n][1], f[n][2])));
	return 0;
}