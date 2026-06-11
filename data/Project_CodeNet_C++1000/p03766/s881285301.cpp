#include<bits/stdc++.h>
using namespace std;

const int N=1001000,mod=1000000007;
typedef long long ll;
int f[N],n,ans;
inline void reduce(int&x){x+=x>>31&mod;}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	f[0]=f[1]=0;f[2]=1;cin>>n;
	for(int i=3;i<=n+1;++i)f[i]=(2ll*f[i-1]-f[i-2]+f[i-3]+mod)%mod;
	reduce(ans=((ll)(n+1)*f[n+1]+(ll)(n-1)*(n-1)%mod*f[n]+f[n-1])%mod);
	for(int i=0;i<=n+1;++i)reduce(ans-=f[i]);
	cout<<ans<<'\n';
	return 0;
}
