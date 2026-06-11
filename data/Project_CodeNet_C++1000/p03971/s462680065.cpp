#include <stdio.h>
#include <iostream>
using namespace std;
using ll = long long;

int main(void) {
	int N, A, B;
	scanf("%d%d%d", &N, &A, &B);
	char S[N];
	scanf("%s", S);
	int passed = 0;
	int passed_abroad = 0;
	for (int i = 0; i < N; i++) {
		char c = S[i];
		if (c == 'a' && passed < A + B) {
			passed++;
			printf("Yes\n");
		} else if (c == 'b' && passed < A + B && passed_abroad < B) {
			passed++;
			passed_abroad++;
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}
