#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int X, A, B;
	scanf("%d %d %d", &X, &A, &B);
	if (B <= A) printf("delicious\n");
	else if (B <= A + X) printf("safe\n");
	else printf("dangerous\n");

	return 0;
}
