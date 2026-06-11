#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);
	int a[100100];
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	int target = 1;
	int cnt = 0;
	while (cnt <= N) {
		cnt++;
		if (a[target - 1] == 2) {
			printf("%d\n", cnt);
			return 0;
		} else {
			target = a[target - 1];
		}
	}
	printf("-1\n");
	return 0;
}
