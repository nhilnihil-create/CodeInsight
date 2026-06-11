#include<bits/stdc++.h>
#define MAXN 2005 
#define P int(1e9+7)
using namespace std;
typedef long long ll;
const int NN = 4e6;

ll qpow(ll x, int n){
	ll res = 1;
	while(n){
		if(n&1) res = res * x % P;
		x = x * x % P;
		n /= 2;
	}
	return res;
}

int N,K;

ll fac[NN+5], ifac[NN+5];
ll dp[MAXN][MAXN];
/*
dp[i][j] = dp[i-1][j] + dp[i][j-1] * (n-j+1) * comb(i+j*(k-1)-1,k-2)
*/

void init(){
	fac[0] = 1;
	for(int i=1;i<=NN;i++){
		fac[i] = fac[i-1] * i % P;
	}
	
	ifac[NN] = qpow(fac[NN], P-2);
	for(int i=NN-1;i>=0;i--){
		ifac[i] = ifac[i+1] * (i+1) % P;
	}
}

ll comb(int n, int k){
	if(k > n) return 0;
	return fac[n] * ifac[k] % P * ifac[n-k] % P;
}

int main(){
	
	cin>>N>>K;
	if(K==1){
		cout<<"1"<<endl;
		return 0;
	}
	init();
	dp[0][0] = 1;
	
	for(int i=1;i<=N;i++){
		for(int j=0;j<=i;j++){
			dp[i][j] = dp[i-1][j];
			if(j>0) dp[i][j] = (dp[i][j] + dp[i][j-1] * (N-j+1) % P * comb((N-i)+(N-j+1)*(K-1)-1, K-2)) % P;
		}
	}
	
	cout<<dp[N][N]<<endl;
	return 0;
}
