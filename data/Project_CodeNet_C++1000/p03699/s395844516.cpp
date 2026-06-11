#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);
	int s[100];
	int sum = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &s[i]);
		sum += s[i];
	}
	if (sum % 10 != 0) {
		printf("%d\n", sum);
		return 0;
	}
	sort(s, s + N);
	for (int i = 0; i < N; i++) {
		if (s[i] % 10 != 0) {
			printf("%d\n", sum - s[i]);
			return 0;
		}
	}
	printf("0\n");
	return 0;
}
