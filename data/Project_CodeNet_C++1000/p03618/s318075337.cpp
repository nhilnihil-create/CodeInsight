#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>

typedef long long LL;

const int MAXN = 2e5 + 10;

int len;
int bin[233];
char s[MAXN];

int main() {
	scanf(" %s", s + 1), len = strlen(s + 1);
	for (int i = 1; i <= len; ++i) ++bin[s[i] - 'a'];
	LL ans = 1LL * len * (len - 1) / 2 + 1;
	for (int i = 0; i < 26; ++i) ans -= 1LL * bin[i] * (bin[i] - 1) / 2;
	printf("%lld\n", ans);
	return 0;
}