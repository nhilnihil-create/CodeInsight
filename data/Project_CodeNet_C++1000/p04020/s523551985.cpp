#include <cstdio>

const int MN = 100005;

int N, A[MN];
long long Ans;

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
	int lst = 0;
	for (int i = 1; i <= N; ++i)
		Ans += (A[i] + lst) / 2,
		lst = A[i] ? (A[i] + lst) % 2 : 0;
	printf("%lld\n", Ans);
	return 0;
}