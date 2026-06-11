#include <cstdio>
#include <algorithm>

typedef long long LL;
const int MN = 300005;

int N, A[MN];
LL Ans;

int main() {
	scanf("%d", &N), N *= 3;
	for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
	std::sort(A + 1, A + N + 1);
	for (int i = N / 3 + 1; i <= N; i += 2) Ans += A[i];
	printf("%lld\n", Ans);
	return 0;
}