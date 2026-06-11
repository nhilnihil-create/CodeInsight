#include <algorithm>
#include <cstdio>
#include <cstring>

typedef long long LL;

const int MAXN = 2000;
const LL INF = 0x3f3f3f3f;

int N, X;
int A[MAXN + 5];
int Dp[MAXN + 5];

int main() {
	scanf("%d%d", &N, &X);
	LL Ans = 1ll << 60;
	for (int i = 1; i <= N; i++)
		scanf("%d", &A[i]), Dp[i] = INF;
	for (int k = 0; k < N; k++) {
		LL cur = 0;
		for (int i = 1; i <= N; i++)
			cur += Dp[i] = std::min(Dp[i], A[(i + k - 1) % N + 1]);
		Ans = std::min(Ans, (LL)k * X + cur);
	}
	printf("%lld", Ans);
	return 0;
}
