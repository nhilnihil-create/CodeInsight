#include <bits/stdc++.h>
using namespace std;

int main() {
	long long A, B, a, b, c = 0; scanf("%lld%lld", &A, &B);
	a = A; b = B;
	while(1) {
		if(A < 2 && B < 2) break;
		if(A < B) swap(A, B);
		long long D = A >> 1;
		A -= D*2; B += D;
		c += D;
	}
	a += c; b += c;
	a /= 3; b /= 3;
	puts(a^b ? "Alice" : "Brown");
	return 0;
}