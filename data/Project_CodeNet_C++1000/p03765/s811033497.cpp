#include <stdio.h>

#define MAXN 100005

char S[MAXN], T[MAXN];
int A[MAXN], B[MAXN], C[MAXN], D[MAXN];
int SA[MAXN], TA[MAXN];

int main() {
	int N, M, Q;

	scanf("%s%s%d", S + 1, T + 1, &Q);
	for(int i = 0; i < Q; i++) scanf("%d%d%d%d", A + i, B + i, C + i, D + i);

	for(N = 1; S[N]; N++) SA[N] = (S[N] == 'A' ? 1 : 0) + SA[N - 1];
	for(M = 1; T[M]; M++) TA[M] = (T[M] == 'A' ? 1 : 0) + TA[M - 1];

	for(int i = 0; i < Q; i++) {
		if((2 * (SA[B[i]] - SA[A[i] - 1] - TA[D[i]] + TA[C[i] - 1]) - B[i] + A[i] + D[i] - C[i]) % 3 == 0)
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
