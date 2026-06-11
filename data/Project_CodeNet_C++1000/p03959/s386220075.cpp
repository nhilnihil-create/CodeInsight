#include <bits/stdc++.h>
using namespace std; 
int main(){
	int N; cin >> N; 
	long long int T[100010] = {}; 
	long long int A[100010] = {}; 
	long long int P = 1e9+7; 
	for(int i = 1; i <= N; i++){
		cin >> T[i]; 
	}
	for(int i = 1; i <= N; i++){
		cin >> A[i]; 
	}
	long long int ans = 1; 
	long long int m1[100010] = {}; 
	long long int m2[100010] = {}; 
	long long int M1[100010] = {}; 
	long long int M2[100010] = {}; 
	for(int i = 1; i <= N; i++){
		if(T[i] != T[i-1]){
			M1[i] = T[i]; m1[i] = T[i]; 
		}
		else{
			M1[i] = T[i]; m1[i] = 1; 
		}
	}
	for(int i = 1; i <= N; i++){
		if(A[i] != A[i+1]){
			M2[i] = A[i]; m2[i] = A[i]; 
		}
		else{
			M2[i] = A[i]; m2[i] = 1; 
		}
		long long int pos = max(min(M1[i], M2[i]) - max(m1[i], m2[i]) + 1, 0LL); 
		ans *= pos; 
		ans = ans % P; 
	}
	cout << ans << endl; 
}