#include <bits/stdc++.h>
using namespace std;
int main() {
	int N; 
	cin >> N; 
	long long int A[100010] = {}; 
	for(int i = 0; i < N; i++) cin >> A[i]; 
	long long int current = 1; 
	long long int ans = 0; 
	for(int i = 0; i < N; i++){
		if(A[i] == current) current ++; 
		else if(A[i] < current) continue; 
		else{
			ans += (A[i] - 1) / current; 
			if(i == 0) current ++; 
		}
	}
	cout << ans << endl; 
}