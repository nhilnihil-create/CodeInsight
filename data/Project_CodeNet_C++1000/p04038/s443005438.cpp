#include<bits/stdc++.h>
#define int long long
#define N 4000005
#define MOD 1000000007
using namespace std;
int n,k,f[2005][2005],inv[N],fac[N];
int C(int x,int y){
	return x>=y?fac[x]*inv[y]%MOD*inv[x-y]%MOD:0;
}
signed main(){
	cin>>n>>k;
	if(k==1){
		cout<<1<<endl;
		return 0;
	}
	fac[0]=inv[0]=inv[1]=1;//first deal
	for(int i=1;i<=n*k;i++)
		fac[i]=fac[i-1]*i%MOD;
	for(int i=2;i<=n*k;i++)
		inv[i]=inv[MOD%i]*(MOD-MOD/i)%MOD;
	for(int i=1;i<=n*k;i++)
		inv[i]=inv[i-1]%MOD*inv[i]%MOD;
	for(int i=0;i<=n;i++)
		f[i][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
//			cout<<i<<" "<<j<<"*"<<"%"<<C(k-2,(n-i)+(n-j+1)*(k-1)-1)<<endl;
			f[i][j]=(f[i-1][j]+C((n-i)+(n-j+1)*(k-1)-1,k-2)*f[i][j-1]%MOD*(n-j+1)%MOD)%MOD;
//			cout<<f[1][1]<<endl;
		}
	}
	cout<<f[n][n];
	return 0;
}