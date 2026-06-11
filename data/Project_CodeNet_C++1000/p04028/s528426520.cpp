#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main(){
  	int N; 
	string S;
  	cin >> N >> S; 
	int L = S.size();
	long long int P = 1e9 + 7;  
	long long int dp[5010][5010] = {}; 
	dp[0][0] = 1; 
	for(int j = 1; j <= 5000; j++){
		dp[0][j] = (dp[0][j-1] + dp[1][j-1]) % P; 
		for(int i = 1; i <= j; i++){
			dp[i][j] = (dp[i+1][j-1] + 2 * dp[i-1][j-1]) % P; 
		}
	}
	long long int Q = 1; 
	for(int i = 0; i < L; i++){
	Q = (Q * (P+1)/2) % P; 
	}
	cout << (dp[L][N] * Q) % P << endl; 
}