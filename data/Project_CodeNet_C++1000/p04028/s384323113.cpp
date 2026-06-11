#include "bits/stdc++.h"
using namespace std;
 
long long dp[5000+10][5000+10];
 
int main(){
	//freopen("input","r",stdin);
	//freopen("output","w",stdout);
	int n;
	string s;
	cin>>n>>s;
	int x = s.size();
	dp[0][0] = 1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=5000;j++){
			dp[i][j] = 2*dp[i-1][j+1] + dp[i-1][max(0,j-1)];
			dp[i][j] %= 1000000007;
		}
	}
	cout<<dp[n][x]<<endl;
	return 0;
}