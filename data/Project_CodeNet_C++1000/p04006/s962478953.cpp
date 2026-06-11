#include <cstdio>
#include <algorithm>

typedef long long LL;
const int MN = 2005;

int N, X, A[MN * 2], B[MN * 2];
LL Ans;

int main() {
	scanf("%d%d", &N, &X);
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &A[i]);
		A[N + i] = B[i] = A[i];
		Ans += B[i];
	}
	for (int k = 1; k < N; ++k) {
		LL Sum = (LL)k * X;
		for (int i = 1; i <= N; ++i) {
			B[i] = std::min(B[i], A[N + i - k]);
			Sum += B[i];
		}
		Ans = std::min(Ans, Sum);
	}
	printf("%lld\n", Ans);
	return 0;
}