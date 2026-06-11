#include <cstdio>
#include <cstring>
#include <algorithm>

const int MN = 105, Sig = 26;

int N;
char S[MN];
int lst[Sig], ans[Sig];

int main() {
	scanf("%s", S + 1), N = strlen(S + 1);
	for (int i = 1; i <= N; ++i) {
		int x = S[i] - 'a';
		ans[x] = std::max(ans[x], i - lst[x] - 1);
		lst[x] = i;
	}
	int tans = N;
	for (int x = 0; x < Sig; ++x) tans = std::min(tans, std::max(ans[x], N - lst[x]));
	printf("%d\n", tans);
	return 0;
}