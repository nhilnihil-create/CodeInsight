#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring> 
#include<cassert>
#include<cmath>
#include<sstream>
#include<fstream>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#include<bitset>
using namespace std;
const long long MOD=1e9+7;
long long quickpow(long long x,int times){
	long long tmp=1;
	while(times){
		if(times&1) tmp=tmp*x%MOD;
		x=x*x%MOD;
		times>>=1;
	}
	return tmp;
}
long long dp[2005][2005],po[5000005],inpo[5000005];
long long C(int n,int m){
	return (po[n]*inpo[m]%MOD*inpo[n-m]%MOD);
}
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	if(k==1){
		cout<<1;
		return 0;
	}
	po[0]=1;
	inpo[0]=1;
	for(int i=1;i<=5000002;i++){
		po[i]=i*po[i-1]%MOD;
		inpo[i]=quickpow(po[i],MOD-2);
	}
	dp[0][0]=1;
//	cout<<C(0,0)<<endl;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i;j++){
			dp[i][j]=(dp[i-1][j]+((j!=0)?dp[i][j-1]*C(k*n-i-(j-1)*(k-1)-1,(k-2))%MOD*(n-j+1):0))%MOD;
		//	cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
		}
	}
	cout<<dp[n][n];
}