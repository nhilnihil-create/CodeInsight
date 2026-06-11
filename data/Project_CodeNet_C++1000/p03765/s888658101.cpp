#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100055;

char A[MAXN];
int B[MAXN], C[MAXN];

int Q;

int main() {
	scanf(" %s", A+1);
	for(int i = 1; A[i]; i++)
		B[i] = B[i-1] + ('A' == A[i] ? 1 : 2);
	scanf(" %s", A+1);
	for(int i = 1; A[i]; i++)
		C[i] = C[i-1] + ('A' == A[i] ? 1 : 2);
	scanf("%d", &Q);
	for(int a, b, c, d; Q--;) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		a = B[b] - B[a-1];
		c = C[d] - C[c-1];
		a %= 3; c %= 3;
		puts(a == c ? "YES" : "NO");
	}
	return 0;
}