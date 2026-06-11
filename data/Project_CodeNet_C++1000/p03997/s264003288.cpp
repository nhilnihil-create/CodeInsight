#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int a, b, h;
	scanf("%d%d%d", &a, &b, &h);
	printf("%d", (a + b) * h / 2);
	return 0;
}
