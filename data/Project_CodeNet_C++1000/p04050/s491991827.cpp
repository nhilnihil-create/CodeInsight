#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 105, LEN = 1e5 + 5;
int n, m, A[N], B[LEN], cnt, deg[LEN], pp[LEN];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &A[i]);
		if (A[i] & 1)
			++cnt;
	}
	if (((n & 1) && cnt >= 2) || ((!(n & 1)) && cnt >= 3)) {
		printf("Impossible\n");
		return 0;
	}
	if (m == 2 && A[1] == 1 && A[2] == 1) {
		printf("1 1\n1\n2\n");
		return 0;
	}
	if (m == 1) {
		if (n == 1) 
			printf("1\n1\n1\n");
//		else if (!(n & 1))
//			printf("%d\n2\n%d %d\n", A[1], n / 2 - 1, n - n / 2 + 1);
//		else
//			printf("%d\n2\n%d %d\n", A[1], n / 2, n - n / 2);
		else
			printf("%d\n2\n%d %d\n", n, 1, n - 1);
		return 0;
	}
	int p1 = 0, p2 = 0;
	for (int i = 1; i <= m; ++i) {
		if (A[i] & 1) {
			if (p1)
				p2 = i;
			else
				p1 = i;
		}
	}
	if (p1)
		swap(A[p1], A[1]);
	if (p2)
		swap(A[p2], A[m]);
	for (int i = 1; i <= m; ++i) {
		printf("%d ", A[i]);
	}
	printf("\n");
	if (A[m] != 1)
		printf("%d\n", m);
	else
		printf("%d\n", m - 1);
	printf("%d ", A[1] + 1);
	for (int i = 2; i <= m - 1; ++i)
		printf("%d ", A[i]);
	if (A[m] != 1)
		printf("%d\n", A[m] - 1);
	return 0;
}