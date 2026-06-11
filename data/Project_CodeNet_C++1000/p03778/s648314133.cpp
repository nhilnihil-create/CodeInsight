#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int W, a, b;
	scanf("%d %d %d", &W, &a, &b);
	if (a + W < b) printf("%d\n", b- (a + W));
	else if (b + W < a) printf("%d\n", a - (b + W));
	else printf("0\n");

	return 0;
}
