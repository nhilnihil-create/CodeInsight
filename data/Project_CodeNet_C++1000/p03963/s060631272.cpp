#include<cstdio>
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int main(void) {
	int N, K;
	scanf("%d %d", &N, &K);
	long long ans = K;
	for (int i = 1; i < N; i++) {
		ans *= K - 1;
	}
	printf("%lld\n", ans);

	return 0;
}
