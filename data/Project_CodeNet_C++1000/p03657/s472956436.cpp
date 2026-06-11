#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int A, B;
	scanf("%d%d", &A, &B);
	if (A % 3 == 0) {
		printf("Possible\n");
	} else if (B % 3 == 0) {
		printf("Possible\n");
	} else if ((A + B) % 3 == 0) {
		printf("Possible\n");
	} else {
		printf("Impossible\n");
	}
	return 0;
}
