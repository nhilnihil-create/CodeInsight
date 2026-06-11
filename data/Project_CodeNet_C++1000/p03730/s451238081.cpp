#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int GCD(int a, int b) {
	if (b == 0) return a;
	return GCD(b, a % b);
}

int main(void) {
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	printf(C % GCD(A, B) == 0 ? "YES\n" : "NO\n");
	return 0;
}
