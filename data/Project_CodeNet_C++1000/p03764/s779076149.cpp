#include<bits/stdc++.h>

using namespace std;
#define int long long
#define N 666666
#define mod 1000000007
int x[N],y[N];
int n,m;
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
	for(int i=1;i<=m;i++) scanf("%lld",&y[i]);
	int ans1=0,ans2=0;
	for(int i=2;i<=n;i++){
		ans1=(ans1+(x[i]-x[i-1])*(i-1)*(n-i+1)%mod);
	}
	for(int i=2;i<=m;i++){
		ans2=(ans2+(y[i]-y[i-1])*(i-1)*(m-i+1)%mod);
	}
	int ans=((ans1%mod)*(ans2%mod))%mod;
	cout<<ans%mod;
	return 0;
}