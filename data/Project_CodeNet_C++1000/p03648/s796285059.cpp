#include <cstdio>
using namespace std;
int main() {
	long long K;
	scanf("%lld", &K);
	printf("50\n");
	long long A[50];
	int phase = K % 50;
	long long N = K / 50 + 49;
	for(int i = 0; i < 50; i++) {
		if(i < phase) {
			A[i] = N + 51 - phase;
		} else {
			A[i] = N - phase;
		}
		printf("%lld", A[i]);
		printf( i < 50 - 1 ? " " : "\n");
	}
	return 0;
}