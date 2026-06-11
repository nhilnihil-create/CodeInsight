#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int N;
	long long ans = 1;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		ans = ans * i % (1000000007);
	}
	printf("%lld\n", ans);

	return 0;
}
