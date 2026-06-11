#include<cstdio>
using ll = long long;

int main(){
	int N;
	scanf("%d", &N);
	int A[N][N];
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j) scanf("%d", &A[i][j]);
	}
	ll answer = 0;
	for (int i = 0; i < N - 1; ++i){
		for (int j = i + 1; j < N; ++j){
			bool flag = true;
			for (int k = 0; k < N; ++k){
				if(k != i && k != j){
					if(A[i][k] + A[k][j] < A[i][j]){
						printf("-1\n");
						return 0;
					}
					if(A[i][k] + A[k][j] == A[i][j]) flag = false;
				}
			}
			if(flag) answer += A[i][j];
		}
	}
	printf("%lld\n", answer);
	return 0;
}