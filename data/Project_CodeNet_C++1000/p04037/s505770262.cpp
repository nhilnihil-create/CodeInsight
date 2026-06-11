#include <cstdio>
#include <algorithm>
const int MaxN = 1e6 + 10;
int F[MaxN], A[MaxN];	
int N; 
bool Cmp(int A, int B) {
	return A > B;
}
int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	std::sort(A + 1, A + 1 + N, Cmp);
	/*SG函数 ↓*/
	int P = 0;
	while(P + 1 < N && P + 1 < A[P + 2]) P += 1;
	int C = (A[P + 1] - P) & 1, B = 1;
	for(int i = P + 2; i <= N && A[i] > P; i++) B ^= 1;
	if(B && C) printf("Second");
	else printf("First");
} 
