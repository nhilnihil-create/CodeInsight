#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);
	int ans = 0;
	for (int i = 0; i < N; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		ans += r - l + 1;
	}
	printf("%d\n", ans);
	return 0;
}
