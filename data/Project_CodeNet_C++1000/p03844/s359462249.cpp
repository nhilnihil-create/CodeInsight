#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const* argv[]) {
	int A, B;
	char op;
	scanf("%d %c %d", &A, &op, &B);
	if (op == '+') printf("%d\n", A + B);
	else printf("%d\n", A - B);

	return 0;
}
