#include <cstdio>

typedef long long LL;
const int MN = 100005;

int N, A[MN], B[MN];
LL Ans;

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%d%d", &A[i], &B[i]);
	for (int i = N; i >= 1; --i) Ans += (B[i] - (A[i] + Ans) % B[i]) % B[i];
	printf("%lld\n", Ans);
	return 0;
}