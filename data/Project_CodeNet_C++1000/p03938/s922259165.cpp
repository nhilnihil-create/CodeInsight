#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;



int main(void) {
	unsigned long long int a[20000], b[20000], tmp;
	int A, X[20000];
	
	cin >> A;

	for (int i = 0; i < A; i++) {
		cin >> X[i];
		X[i]--;
		a[i] = 30000 * (i + 1);
		b[i] = 30000 * (A - (i + 1));
	}

	for (int i = 0; i < A; i++) {
		b[X[i]] += (i + 1);
	}

	for (int i = 0; i < A; i++) {
		printf("%lld", a[i]);
		if (i != A - 1) {
			printf(" ");
		}
	}
	printf("\n");
	for (int i = 0; i < A; i++) {
		printf("%lld", b[i]);
		if (i != A - 1) {
			printf(" ");
		}
	}
	return 0;
}