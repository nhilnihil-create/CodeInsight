#include <bits/stdc++.h>
using namespace std;
int main(){
	int N; 
	cin >> N; 
	long long int A[100010] = {}; 
	long long int S = 0; 
	for(int i = 0; i < N; i++){
		cin >> A[i]; 
		S += A[i]; 
	}
	A[N] = A[0]; 
	bool possible = true; 
  	long long int sum = (long long) N * (N + 1) / 2; 
	if(S % sum != 0) possible = false; 
	else{
		long long int T = S / sum; // 操作回数
		for(int i = 0; i < N; i++){
			long long int a = T - (A[i+1] - A[i]); 
			if(a < 0 || a % (long long) N != 0){
				possible = false; break;
			}
		}
	}
	if(possible) cout << "YES" << endl;
	else cout << "NO" << endl; 
}