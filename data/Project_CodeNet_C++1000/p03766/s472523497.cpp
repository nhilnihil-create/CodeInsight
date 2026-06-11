#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int n,f[1000005];
int sum;

int main(){
	cin>>n;
	f[0]=f[1]=1;
	sum=2;
	for(int i=2;i<=n;i++){
		f[i]=(sum-f[i-2]+mod)%mod;
		sum=(sum+f[i])%mod;
	}
	f[n]=(f[n]+1ll*f[n-1]*(n-1)%mod)%mod;
	for(int i=2;i<=n;i++) f[n]=(f[n]+1ll*(n-i+1)*f[n-i]%mod)%mod;
	int ans=f[n];
	for(int i=0;i<n-1;i++) ans=(ans+1ll*(n-1)*(n-1)%mod*f[i]%mod)%mod;
	cout<<ans<<endl;

	return 0;
}