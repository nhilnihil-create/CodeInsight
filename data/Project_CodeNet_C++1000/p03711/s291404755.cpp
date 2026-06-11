#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int x, y;
	scanf("%d %d", &x, &y);
	int g0[] = {1, 3, 5, 7, 8, 10, 12};
	int g1[] = {4, 6, 9, 11};
	if (x == 2 && y == 2) {
		printf("Yes\n");
		return 0;
	}
	bool xflag = false, yflag = false;
	for (int i = 0; i < 7; i++) {
		if (g0[i] == x) xflag = true;
		if (g0[i] == y) yflag = true;
	}
	if (xflag && yflag) {
		printf("Yes\n");
		return 0;
	}
	xflag = false;
	yflag = false;
	for (int i = 0; i < 4; i++) {
		if (g1[i] == x) xflag = true;
		if (g1[i] == y) yflag = true;
	}
	if (xflag && yflag) {
		printf("Yes\n");
		return 0;
	}
	printf("No\n");
	return 0;
}
