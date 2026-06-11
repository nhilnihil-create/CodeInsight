#include <cstdio>

typedef long long LL;
const int MN = 200005, Sig = 26;

char s[MN];
int buk[Sig];
LL Ans;

int main() {
	scanf("%s", s + 1);
	for (int i = 1; s[i]; ++i)
		Ans += i - ++buk[s[i] - 'a'];
	printf("%lld\n", Ans + 1);
	return 0;
}