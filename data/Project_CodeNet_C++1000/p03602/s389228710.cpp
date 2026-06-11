#include<bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	int A[N][N];
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> A[i][j];
		}
	}
	long long ans = 0;
	for(int i=0; i<N; i++){
		for(int j=i+1; j<N; j++){
			int f = 0;
			for(int k=0; k<N; k++){
				if(i != k && j != k){
					if(A[i][j] > A[i][k] + A[k][j]){
						cout << -1 << endl;
						return 0;
					}else if(A[i][j] == A[i][k] + A[k][j]){
						f = 1;
					}
				}
			}
			if(!f) ans += A[i][j];
		}
	}
	cout << ans << endl;
	return 0;
}