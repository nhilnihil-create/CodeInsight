#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int N, K;
	scanf("%d %d", &N, &K);
	int x[100];
	int ans = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &x[i]);
		ans += min(x[i], abs(x[i] - K)) * 2;
	}
	printf("%d\n", ans);
	return 0;
}
