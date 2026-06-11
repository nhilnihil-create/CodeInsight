#include<cstdio>
#include<iostream>
using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		ans += i;
	}
	printf("%d", ans);
	return 0;
}
