#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define lol(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
typedef long long ll;
using namespace std;
#define N 5010
int n;
string s;
ll dp[N][N];
int main(){
	lol(i,N)lol(j,N)dp[i][j]=0;
	dp[0][0]=1;
	lol(i,N-1)lol(j,N){
		dp[i+1][j+1]=(dp[i+1][j+1]+2*dp[i][j])%mod;
		dp[i+1][max(0,j-1)]=(dp[i+1][max(0,j-1)]+dp[i][j])%mod;
	}
	cin>>n>>s;
	ll ans=dp[n][s.size()];
	lol(i,s.size())ans=ans*500000004%mod;
	cout<<ans<<endl;
	return 0;
}
