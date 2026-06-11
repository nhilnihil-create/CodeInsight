#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const* argv[]) {
	int A, B, C, D;
	scanf("%d %d %d %d", &A, &B, &C, &D);
	printf("%d\n", max(A * B, C * D));
	return 0;
}
