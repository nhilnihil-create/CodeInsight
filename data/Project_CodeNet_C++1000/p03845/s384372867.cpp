#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const* argv[]) {
	int N;
	scanf("%d", &N);
	int T[100];
	for (int i = 0; i < N; i++) {
		scanf("%d", &T[i]);
	}
	int M;
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int P, X;
		scanf("%d %d", &P, &X);
		int ans = 0;
		for (int j = 0; j < N; j++) {
			if (j == P - 1) ans += X;
			else ans += T[j];
		}
		printf("%d\n", ans);
	}

	return 0;
}
