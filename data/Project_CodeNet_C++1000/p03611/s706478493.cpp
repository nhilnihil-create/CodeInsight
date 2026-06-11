#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);
	int A[101000] = {0};
	for (int i = 0; i < N; i++) {
		int a;
		scanf("%d", &a);
		A[a]++;
		A[a + 1]++;
		A[a + 2]++;
	}
	int ans = 0;
	for (int i = 0; i < 101000; i++) {
		ans = max(ans, A[i]);
	}
	printf("%d\n", ans);
	return 0;
}
