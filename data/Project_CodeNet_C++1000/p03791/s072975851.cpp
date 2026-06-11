#include <bits/stdc++.h>
using namespace std;
int main(){
	int N, X[100010], A[100010]; 
	cin >> N; 
	for(int i = 1; i <= N; i++){
		cin >> X[i]; 
		int tmp = i - 1 - (X[i] - 1) / 2; 
		A[i] = max(A[i-1], tmp); 
	}
	long long P = 1000000007; 
	long long ans = 1LL; 
	for(int i = 1; i <= N; i++){
		ans *= (long long) i - A[i-1]; 
		ans %= P; 
	}
	cout << ans << endl; 
}