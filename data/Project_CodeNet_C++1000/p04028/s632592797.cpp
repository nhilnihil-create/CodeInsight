#include<iostream>
#include<cstring>
#define N 5000
#define MOD 1000000007
using namespace std;
typedef long long LL;
LL dp[N+2][N+2];
LL solve()
{
	int K; cin >> K;
	
	string s; cin >> s; 
	int n = s.length();
	
	memset(dp,0,sizeof dp);
	dp[0][0] = 1;
	for(int k = 1; k <= K; k++)
		for(int x = 0; x <= k; x++)
			if(x==0)
				dp[x][k] = (dp[x][k-1]+2*dp[x+1][k-1])%MOD;
			else
				dp[x][k] = (dp[x-1][k-1]+2*dp[x+1][k-1])%MOD;
			
	return dp[n][K];
}
int main()
{
	cout<<solve()<<endl;
	return 0;
}
