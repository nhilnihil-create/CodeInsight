// KALAM
# include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 77 , Mod = 1e9 + 7;
int n , dp[N] , ps[N];
int main(){
	scanf("%d" , & n);ps[0] = 1;
	dp[1] = ps[1] = n ;ps[1]++;
	for(int i = 2;i <= n;i++){
		dp[i] = (dp[i - 1] * 1ll + (n - 1) * 1ll * (n - 1) + 1 + n - i) % Mod;
		if(i > 2)dp[i] = (dp[i] + ps[i - 3]) % Mod;
		ps[i] = (ps[i - 1] + dp[i]) % Mod;
	}
	printf("%d" , dp[n]);
	return (0);
}