#include <cstdio>

const int MN = 305, MM = 305;

int N, M, A[MN][MM], cho[MM], p[MN], buk[MM], Ans;

int main() {
	scanf("%d%d", &N, &M), Ans = N;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			scanf("%d", &A[i][j]);
	for (int j = 1; j <= M; ++j) cho[j] = 1;
	for (int i = 1; i <= N; ++i) p[i] = 1;
	for (int k = 1; k <= M; ++k) {
		for (int j = 1; j <= M; ++j) buk[j] = 0;
		for (int i = 1; i <= N; ++i) {
			while (!cho[A[i][p[i]]]) ++p[i];
			++buk[A[i][p[i]]];
		}
		int mxi = 0;
		for (int j = 1; j <= M; ++j)
			if (buk[mxi] < buk[j]) mxi = j;
		if (Ans > buk[mxi]) Ans = buk[mxi];
		cho[mxi] = 0;
	}
	printf("%d\n", Ans);
	return 0;
}