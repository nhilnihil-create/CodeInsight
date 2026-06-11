#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[3000000],b[3000000],ans=0,zero=0;
main() {
	cin>>n>>k;++k;
	for(int i=1;i<=n;i++) scanf("%lld%lld",&a[i],&b[i]);
	for(int i=30;i>=0;i--) {
		if(k>>i&1) {
			zero^=(1<<i);
			int res=0;
			for(int i=1;i<=n;i++) {
				if(!(a[i]&zero)) {
					res+=b[i];
				}
			}
			ans=max(ans,res);
		}
		zero^=(1<<i);
	}
	cout<<ans<<"\n";
}