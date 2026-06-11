#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int A, B, C, D;
	scanf("%d %d %d %d", &A, &B, &C, &D);
	printf("%d\n", max(0, min(B, D) - max(A, C)));
	return 0;
}
