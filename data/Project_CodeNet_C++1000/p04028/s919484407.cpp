#include <iostream>
#include <string>

#define mod 1000000007
using namespace std;

long long dp[5010][5010];
int main(){
	int i,j,n;
	string s;
	cin >> n >> s;
	dp[0][0] = 1;
	for(i=0;i<=n;i++){
		for(j=0;j<=n;j++){
			if(j==0){
				dp[i+1][j] += dp[i][j];
				dp[i+1][j+1] += dp[i][j];
			}else{
				dp[i+1][j-1] += 2*dp[i][j];
				dp[i+1][j+1] += dp[i][j];
			}
			dp[i+1][j-1] %= mod;
			dp[i][j] %= mod;
			dp[i+1][j+1] %= mod;
		}
	}
	
	cout << dp[n][s.size()] << endl;
}
