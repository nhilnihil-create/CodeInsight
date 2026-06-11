#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf(b - a == c - b ? "YES\n" : "NO\n");

	return 0;
}
