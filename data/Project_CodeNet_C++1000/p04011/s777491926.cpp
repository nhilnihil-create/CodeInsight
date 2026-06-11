#include<cstdio>
#include<iostream>
using namespace std;

int main(void) {
	int N, K, X, Y;
	scanf("%d%d%d%d", &N, &K, &X, &Y);
	if (N <= K) {
		printf("%d\n", X * N);
	} else {
		printf("%d\n", X * K + Y * (N - K));
	}
	return 0;
}
