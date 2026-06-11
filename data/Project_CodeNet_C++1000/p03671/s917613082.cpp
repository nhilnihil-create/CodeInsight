#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int bel[3];
	for (int i = 0; i < 3; i++) {
		scanf("%d", &bel[i]);
	}
	sort(bel, bel + 3);
	printf("%d", bel[0] + bel[1]);
	return 0;
}
