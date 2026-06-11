#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int X, t;
	scanf("%d %d", &X, &t);
	printf("%d\n", max(0, X - t));
	return 0;
}
