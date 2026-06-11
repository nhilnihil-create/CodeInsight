#include <iostream>
using namespace std;
long long i,j,mod=1e9+7,n,m,dp[2][5005];
string s;
int main(){
	cin>>n>>s;
	m=s.size();
	dp[0][0]=1;
	for (i=1;i<=n;i++){
		dp[i&1][0]=(dp[(i-1)&1][0]+dp[(i-1)&1][1]*2)%mod;
		for (j=1;j<=n;j++){
			dp[i&1][j]=(dp[(i-1)&1][j-1]+dp[(i-1)&1][j+1]*2)%mod;
		}
	}
	cout<<dp[n&1][m]<<endl;
	return 0;
}