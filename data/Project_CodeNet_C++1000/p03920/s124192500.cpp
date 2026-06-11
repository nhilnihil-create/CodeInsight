#include <bits/stdc++.h>
using namespace std;
int main(){
	int A[10010] = {}; 
	for(int i = 1; i < 10000; i++){
		A[i] = i * (i + 1) / 2; 
	}
	int N; 
	cin >> N; 
	int K = lower_bound(A, A + 10000, N) - A; 
	int missing = A[K] - N; 
	for(int i = 1; i <= K; i++){
		if(i == missing) continue; 
		cout << i << endl; 
	}
}