#include <cstdio>

int N, Ans;

int main() {
	scanf("%d", &N);
	int lst = 0, sgn = 0;
	for (int i = 1; i <= N; ++i) {
		int x;
		scanf("%d", &x);
		if (!lst) ++Ans;
		else if (!sgn) sgn = x > lst ? 1 : x < lst ? -1 : 0;
		else if (sgn == 1) {
			if (x < lst) ++Ans, sgn = 0;
		} else {
			if (x > lst) ++Ans, sgn = 0;
		}
		lst = x;
	}
	printf("%d\n", Ans);
	return 0;
}