#include <cstdio>
#include <iostream>

#define For(i, j, k) for(int i = j; i <= k; i++)

const int N = 100010;

int A[N], m, n;

int main(){
	scanf("%d%d", &m, &n);
	int c = 0;
	For(i, 1, n) scanf("%d", &A[i]), c += A[i] & 1;
	if(c > 2){
		puts("Impossible");
		return 0;
	}
	if(n == 1){
		if(A[1] == 1) puts("1\n1\n1");
		else printf("%d\n2\n%d %d\n", A[1], A[1] - 1, 1);
		return 0;
	}
	For(i, 1, n)
		if(A[i] & 1) std::swap(A[i], A[c-- == 2 ? 1 : n]);
	For(i, 1, n) printf("%d%c", A[i], i == n ? '\n' : ' ');
	++A[1], --A[n];
	if(!A[n]) --n;
	printf("%d\n", n);
	For(i, 1, n) printf("%d%c", A[i], i == n ? '\n' : ' ');
	return 0;
}