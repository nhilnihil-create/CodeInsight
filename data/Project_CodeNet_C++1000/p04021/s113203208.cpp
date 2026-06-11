#include <cstdio>
#include <algorithm>

const int MN = 100005;

int N, A[MN], B[MN], Ans;

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%d", &A[i]), B[i] = A[i];
	std::sort(B + 1, B + N + 1);
	for (int i = 1; i <= N; ++i)
		Ans += (std::lower_bound(B + 1, B + N + 1, A[i]) - B - i) & 1;
	printf("%d\n", Ans >> 1);
	return 0;
}