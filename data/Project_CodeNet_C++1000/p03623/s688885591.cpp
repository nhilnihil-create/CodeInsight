#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int x, a, b;
	scanf("%d %d %d", &x, &a, &b);
	printf(abs(x - a) < abs(x - b) ? "A\n" : "B\n");
	return 0;
}
