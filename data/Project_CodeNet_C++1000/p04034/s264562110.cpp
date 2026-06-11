#include <cstdio>

const int MN = 100005;

int N, M, Ans;
int num[MN], typ[MN];

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; ++i)
		num[i] = 1, typ[i] = i == 1;
	for (int i = 1; i <= M; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (num[x] == 1) {
			if (typ[x] == 1) typ[y] = 1;
			else if (typ[x] == 2) typ[y] = 2;
			typ[x] = 0;
		} else if (typ[x] != 0) typ[x] = typ[y] = 2;
		--num[x], ++num[y];
	}
	for (int i = 1; i <= N; ++i) if (typ[i]) ++Ans;
	printf("%d\n", Ans);
	return 0;
}