#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int N = 5e3 + 10;

int k , n , dp[N][N];
char s[N];

int Add(int a , int b){
	return a + b > mod ? a + b - mod : a + b;
}

int Mul(int a , int b){
	return 1ll * a * b % mod;
}

int Pow(int a , int k){
	if(k == 1) return a;
	int S = Pow(a , k >> 1);
	if(k & 1) return Mul(a , Mul(S , S));
	else return Mul(S , S);
}

int main(){
	scanf("%d %s" , &k , s) , n = strlen(s);
	dp[0][0] = 1;
	for(int i = 0; i <= k; i++)
		for(int j = 0; j <= i; j++){
			dp[i + 1][j + 1] = Add(dp[i + 1][j + 1] , dp[i][j] * 2);
			dp[i + 1][max(j - 1 , 0)] = Add(dp[i + 1][max(j - 1 , 0)] , dp[i][j]);
		}
	printf("%d" , Mul(dp[k][n] , Pow(Pow(2 , n) , mod - 2)));
	return 0;
}