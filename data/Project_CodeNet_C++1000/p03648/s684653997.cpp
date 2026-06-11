#include <bits/stdc++.h>
using namespace std;

typedef long long int64;
int64 k;

int main() {
	scanf("%lld", &k);

	int64 c = k / 50;
	int64 r = k % 50;

	if(c == 0) {
		if(k == 0) {
			printf("2\n0 0\n");
			return 0;
		}

		if(k == 1) {
			printf("2\n2 0\n");
			return 0;
		}

		printf("%lld\n", k);

		for(int i = 1; i <= k; i++) {
			printf("%lld", k);
			printf(i == k ? "\n" : " ");
		}

		return 0;
	}

	printf("50\n");

	for(int i = 1; i <= r; i++)
		printf("%lld ", 50 + c - i + 1);

	for(int i = 1; i <= 50 - r; i++) {
		printf("%lld", 49 + c - r);
		printf(i == 50 - r ? "\n" : " ");
	}

	return 0;
}