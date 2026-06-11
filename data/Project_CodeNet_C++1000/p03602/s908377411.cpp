#include <iostream>
#define N_MAX 300
#define INF (2<<21)
using namespace std;

int N;
int E[N_MAX][N_MAX];
int A[N_MAX][N_MAX];

void warshall_floyd(){
	for (int k=0; k<N; k++){
		for (int i=0; i<N; i++){
			for (int j=0; j<N; j++){
				if (E[i][j] > E[i][k] + E[k][j]){
					E[i][j] = E[i][k] + E[k][j];
				}
			}
		}
	}
}

int main(void){
	cin >> N;

	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			cin >> E[i][j];
			A[i][j] = E[i][j];
		}
	}

	for (int k=0; k<N; k++){
		for (int i=0; i<N; i++){
			for (int j=0; j<N; j++){
				if(k == i || k == j || i == j || E[i][k] == INF || E[k][j] == INF) continue;
				if (E[i][j] > E[i][k] + E[k][j]){
					cout << "-1" << endl;
					return 0;
				} else if (E[i][j] == E[i][k] + E[k][j]){
					A[i][j] = INF;
				}
			}
		}
	}

	long long int sum = 0;
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			if (A[i][j] != INF) sum += A[i][j];
		}
	}

	cout << (sum/2) << endl;
	return 0;
}