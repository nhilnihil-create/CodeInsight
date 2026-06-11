#include<cstdio>
#include<algorithm>
const static int MAX_N = 50;
const static int MAX_M = 50;
bool A[MAX_N][MAX_N];
bool B[MAX_M][MAX_M];

int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	char a;
	for (int i = 0; i < N; ++i){
		scanf("\n");
		for (int j = 0; j < N; ++j){
			scanf("%c", &a);
			A[i][j] = a == '.';
		}
	}
	for (int i = 0; i < M; ++i){
		scanf("\n");
		for (int j = 0; j < M; ++j){
			scanf("%c", &a);
			B[i][j] = a == '.';
		}
	}
	for (int A_begin_x = 0; A_begin_x < N - M + 1; ++A_begin_x){
		for (int A_begin_y = 0; A_begin_y < N - M + 1; ++A_begin_y){
			bool flag = true;
			for (int B_x = 0; B_x < M; ++B_x){
				for (int B_y = 0; B_y < M; ++B_y){
					if(A[A_begin_x + B_x][A_begin_y + B_y] ^ B[B_x][B_y]){
						flag = false;
						break;
					}
				}
				if(!flag) break;
			}
			if(flag){
				printf("Yes\n");
				return 0;
			}
		}
	}
	printf("No\n");
	return 0;
}