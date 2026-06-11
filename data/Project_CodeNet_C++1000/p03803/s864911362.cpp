#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int A, B;
	scanf("%d%d", &A, &B);
	int card[13];
	for (int i = 0; i < 12; i++) {
		card[i] = i + 2;
	}
	card[12] = 1;
	int a, b;
	for (int i = 0; i < 13; i++) {
		if (card[i] == A) a = i;
		if (card[i] == B) b = i;
	}

	if (a > b) {
		printf("Alice\n");
	} else if (a < b) {
		printf("Bob\n");
	} else {
		printf("Draw\n");
	}
	return 0;
}
