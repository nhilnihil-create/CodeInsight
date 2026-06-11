#include<bits/stdc++.h>
#define M 1000005
#define L long long
#define MOD 1000000007
using namespace std;
L f[M]={0},g[M]={0};
int main(){
	L n,ans=0; cin>>n;
	f[1]=1;
	for(L i=1;i<=n;i++){
		f[i]=(f[i]+(i>=3?g[i-3]:0)+f[i-1])%MOD;
		g[i]=(g[i-1]+f[i])%MOD;
		if(i<n) ans=(ans+f[i]*(n-1)%MOD*(n-1)+f[i]*min(n-1,i+1))%MOD;
	}
	ans=(ans+f[n]*n)%MOD;
	cout<<ans<<endl;
}