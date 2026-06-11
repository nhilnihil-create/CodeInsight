#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

const int maxn = 2001;

long long int dp[maxn][maxn];
long long int fac[4000001],inv[4000001];
void update(long long int& x,long long int y){
	x=(x+y)%mod;
}
long long int C(long long int N,long long int K){
	return fac[N]*inv[K]%mod*inv[N-K]%mod;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	dp[0][0]=1;
	cin>>n>>k;
	fac[0]=inv[0]=fac[1]=inv[1]=1;
	for(int i=2;i<=4000000;i++)
		fac[i]=fac[i-1]*i%mod;
	for(int i=2;i<=4000000;i++)
		inv[i]=(mod-mod/i*inv[mod%i]%mod)%mod;
	for(int i=2;i<=4000000;i++)
		inv[i]=inv[i-1]*inv[i]%mod;
	if(k==1){
		cout<<1<<endl;
		return 0;
	}
	for(int i=0;i<=n;i++)
		for(int j=i;j<=n;j++){
			if(i==0&&j==0)	continue;
			if(j>i)
				update(dp[i][j],C(i+j*(k-1)-1,k-2)*dp[i][j-1]);
			if(i>0)
				update(dp[i][j],dp[i-1][j]);
		}
	cout<<dp[n][n]*fac[n]%mod<<endl;
}
