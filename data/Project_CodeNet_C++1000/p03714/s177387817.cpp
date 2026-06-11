#include <bits/stdc++.h>
#include <algorithm>
#include <queue>
using namespace std;
int main() {
	int N; 
	cin >> N; 
	long long int A[300010] = {}; 
	priority_queue<long long int, vector<long long int>,greater<long long int>> P1; 
	priority_queue<long long int, vector<long long int>> P2;
	long long int left = 0, right = 0;  
	for(int i = 0; i < N * 3; i++) {
		cin >> A[i]; 
		if(i < N){left += A[i]; P1.push(A[i]);}
		if(i >= N * 2){right += A[i]; P2.push(A[i]);}
	}
	long long int L[300010] = {}; long long int R[300010] = {}; 
	L[N - 1] = left, R[N * 2 - 1] = right; 
	for(int i = N; i <= N * 2 - 1; i++){
		L[i] = L[i-1] + A[i];
		P1.push(A[i]);  
		L[i] -= P1.top(); 
		P1.pop(); 
	}
	for(int i = N * 2 - 2; i >= N - 1; i--){
		R[i] = R[i+1] + A[i+1];
		P2.push(A[i+1]);  
		R[i] -= P2.top(); 
		P2.pop(); 
	}
	long long int ans = -1e15; 
	for(int i = N - 1; i <= N * 2 - 1; i++){
		ans = max(ans, L[i] - R[i]); 
	}
	cout << ans << endl; 
}