#include<cstdio>
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int isColor(int rate) {
	if (rate <= 399) return 0;
	else if (rate <= 799) return 1;
	else if (rate <= 1199) return 2;
	else if (rate <= 1599) return 3;
	else if (rate <= 1999) return 4;
	else if (rate <= 2399) return 5;
	else if (rate <= 2799) return 6;
	else if (rate <= 3199) return 7;
	else return 8;
}

int main(void) {
	int N;
	scanf("%d", &N);
	set<int> colors;
	int flee = 0;
	for (int i = 0; i < N; i++) {
		int a;
		scanf("%d", &a);
		int color = isColor(a);
		if (color <= 7) colors.insert(color);
		else flee++;
	}
	int M, m;
	m = max((int)colors.size(), 1);
	M = (int)colors.size() + flee;
	printf("%d %d\n", m, M);
	return 0;
}
