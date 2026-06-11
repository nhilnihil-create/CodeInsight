#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int N, M;
	scanf("%d %d", &N, &M);
	int ans[50] = {0};
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		ans[a - 1]++;
		ans[b - 1]++;
	}
	for (int i = 0; i < N; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}
