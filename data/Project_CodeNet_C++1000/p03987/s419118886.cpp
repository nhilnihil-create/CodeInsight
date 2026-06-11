#include <cstdio>

typedef long long LL;
const int MN = 200005;

int N, A[MN], L[MN], R[MN];
int stk[MN], tp;
LL Ans;

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
	stk[tp = 1] = 0;
	for (int i = 1; i <= N; ++i) {
		while (A[stk[tp]] > A[i]) R[stk[tp--]] = i;
		L[i] = stk[tp], stk[++tp] = i;
	}
	while (tp) R[stk[tp--]] = N + 1;
	for (int i = 1; i <= N; ++i) Ans += (LL)(i - L[i]) * (R[i] - i) * A[i];
	printf("%lld\n", Ans);
	return 0;
}