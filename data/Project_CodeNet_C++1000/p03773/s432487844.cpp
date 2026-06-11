#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int A, B;
	scanf("%d%d", &A, &B);
	printf("%d\n", (A + B) % 24);

	return 0;
}
