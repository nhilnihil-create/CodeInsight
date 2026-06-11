#include <cstdio>
#include <algorithm>
using namespace std;
const int NN = 505, NLEN = 500 * 500 + 5;
int A[NN], N, ans[NLEN], id[NN];
bool cmp(int u, int v) { return A[u] < A[v]; }
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &A[i]);
		ans[A[i]] = i;
		id[i] = i;
	}
	sort(id + 1, id + N + 1, cmp);
	//这需要给 A[i]排序
	int p = 1;
	for (int i = 1; i <= N; ++i) {
		int cnt = 0;
		for (int j = 1; j < A[id[i]]; ++j) {
			if (ans[j] == 0) {
				if (cnt == id[i] - 1)
					break ;
				++cnt;
				ans[j] = id[i];
			}
		}
		if (cnt < id[i] - 1) {
			printf("No\n");
			return 0;
		}
	}
	for (int i = 1; i <= N; ++i) {
		int cnt = 0;
		for (int j = A[id[i]] + 1; j <= N * N; ++j) {
			if (cnt == N - id[i])
				break ; //这句话得放在前面，不能放在后面
			if (!ans[j]) {
				ans[j] = id[i];
				++cnt;
			}
		}
		if (cnt != N - id[i]) { //记得判这个
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	for (int i = 1; i <= N * N; ++i)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}
/*
4
3 4 16 9
*/