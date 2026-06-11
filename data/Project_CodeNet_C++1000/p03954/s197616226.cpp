#include <cstdio>
using namespace std;
const int NN = 1e5 + 5, N2N = NN * 2 - 1;
int N, A[N2N], B[N2N];
bool check(int m) {
	for (int i = 1; i <= 2 * N - 1; ++i) B[i] = (A[i] >= m);
	bool type = 0;
	for (int i = 1; i < 2 * N - 1; ++i)
		if (B[i] == B[i + 1]) {
			type = 1;
			break ;
		}
	if (!type) {
		if ((N - 1) % 2 == 0)
			return B[N];
		else return B[N] ^ 1;
	} else {
/*		printf("B : ");
		for (int i = 1; i <= 2 * N - 1; ++i)
			printf("%d ", B[i]);
		printf("\n");*/
		int p1 = 2 * N; //有可能右边没有，所以得有个初始值
		for (int i = N; i < 2 * N - 1; ++i)
			if (B[i] == B[i + 1]) {
				p1 = i;
				break ;
			}
		int p2 = 0;
		for (int i = 1; i < N; ++i)
			if (B[i] == B[i + 1]) {
				p2 = i + 1;
//				break ; //这里不能 break...要找到最靠右的
			}
//		printf("p1 : %d p2 : %d\n", p1, p2);
		return B[((p1 - N) > (N - p2)) ? p2 : p1];
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= 2 * N - 1; ++i)
		scanf("%d", &A[i]);
	int L = 1, R = 2 * N - 1, ans = 0;
	while (L <= R) {
		int m = (L + R) >> 1;
		if (check(m)) {
			ans = m;
			L = m + 1;
		} else R = m - 1;
	}
	printf("%d\n", ans);
//	printf("check(6) : %d\n", check(6));
	return 0;
}
/*
5
5 4 8 9 1 6 3 2 7 
*/