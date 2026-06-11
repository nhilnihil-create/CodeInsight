#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int A, B;
	scanf("%d%d", &A, &B);
	if (A + B >= 10) {
		printf("error\n");
	} else {
		printf("%d", A + B);
	}
	return 0;
}
