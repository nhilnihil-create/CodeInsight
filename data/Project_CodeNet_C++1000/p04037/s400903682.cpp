#include <cstdio>
#include <algorithm>

const int MN = 100005;

int N, A[MN];
int que[MN], l, r;

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
	std::sort(A + 1, A + N + 1);
	l = 1, r = 0;
	int lstc = 0;
	for (int i = 2; i <= N; ++i) {
		if (A[i] == A[i - 1]) lstc ^= 1;
		else {
			int c = ~(A[i] - A[i - 1]) & 1;
			if (c != lstc) que[++r] = A[i - 1] - lstc + i;
			lstc = 0;
		}
		while (l <= r && que[l] <= i) ++l;
	}
	puts(lstc ^ (A[N] & 1) ^ ((r - l) & 1) ? "First" : "Second");
	return 0;
}