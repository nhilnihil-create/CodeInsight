#include <cstdio>
#include <algorithm>

typedef long long LL;
const int MN = 100005;

int N, K, A[MN];
LL S1p[MN], S1s[MN];
LL S2p[MN], S2s[MN];
LL Sum[MN], Ans;

int main() {
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= N; ++i) scanf("%d", &A[i]), Sum[i] = Sum[i - 1] + A[i];
	for (int i = 1; i <= N; ++i)
		S1p[i] = S1p[i - 1] + (A[i] > 0 ? A[i] : 0),
		S2p[i] = S2p[i - 1] + (A[i] < 0 ? A[i] : 0);
	for (int i = N; i >= 1; --i)
		S1s[i] = S1s[i + 1] + (A[i] > 0 ? A[i] : 0),
		S2s[i] = S2s[i + 1] + (A[i] < 0 ? A[i] : 0);
	for (int i = K; i <= N; ++i)
		Ans = std::max(Ans, Sum[i] - Sum[i - K] + S1p[i - K] + S1s[i + 1]),
		Ans = std::max(Ans, Sum[N] - (Sum[i] - Sum[i - K] + S2p[i - K] + S2s[i + 1]));
	printf("%lld\n", Ans);
	return 0;
}