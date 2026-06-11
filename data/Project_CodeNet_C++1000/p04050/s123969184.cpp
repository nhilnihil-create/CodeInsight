#include <bits/stdc++.h>
using namespace std;
int main(){
	int N, M; 
	cin >> N >> M; 
	int A[110] = {}; 
	int odd = 0; 
	int L = 123; int R = 456; 
	for(int i = 0; i < M; i++){
		cin >> A[i]; 
		if(A[i] % 2) odd ++; 
		if((A[i] % 2) && odd == 1) L = i; 
		if((A[i] % 2) && odd == 2) R = i; 
	}
	if(odd > 2){
		cout << "Impossible" << endl; 
	}
	else{
		if(odd == 2){
			swap(A[L], A[0]); 
			swap(A[R], A[M-1]); 
		}
		if(odd == 1){
			swap(A[L], A[0]); 
		}
		for(int i = 0; i < M; i++){
			cout << A[i] << " "; 
		}
		cout << endl; 
     	if(N == 1){
			cout << 1 << endl << 1 << endl; 
		}
		else if(odd == 0 || (N > 1 && M == 1)){
			cout << M+1 << endl; 
			cout << 1 << " "; 
			for(int i = 0; i < M-1; i++){
				cout << A[i] << " "; 
			}
			cout << A[M-1] - 1 << endl; 
		}
		else if(odd == 1 || (odd == 2 && A[M-1] != 1)){
			cout << M << endl; 
			cout << A[0] + 1 << " "; 
			for(int i = 1; i < M-1; i++){
				cout << A[i] << " "; 
			}
			cout << A[M-1] - 1 << endl; 
		}
		else if(odd == 2 && A[M-1] == 1){
			cout << M-1 << endl; 
			cout << A[0] + 1 << " "; 
			for(int i = 1; i < M-1; i++){
				cout << A[i] << " "; 
			}
			cout << endl; 
		}
	}
}