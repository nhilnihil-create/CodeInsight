#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
#define MOD 1000000007
using namespace std;
typedef long long ll;

int dp[6000][6000];

ll ppow(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)res=(res*a)%MOD;
		a=(a*a)%MOD;
		b>>=1;
	}
	return res;
}
int main(){
	int n;string s;cin>>n>>s;
	dp[0][0]=1;
	rep(i,n)rep(j,n){
		(dp[i+1][j+1]+=dp[i][j]*2)%=MOD;
		(dp[i+1][max(0,j-1)]+=dp[i][j])%=MOD;
	}
	cout<<(dp[n][s.size()]*ppow(ppow(2,s.size()),MOD-2))%MOD<<endl;
}