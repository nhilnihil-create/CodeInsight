#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll n,k,a[20];
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	ll ans=1e18;
	for(int i=0;i<(1ll<<n);i++){
		bool f[20]={};
		ll yojo=0;
		for(int j=0;j<n;j++){
			ll num=1ll<<j;
			if(i&num){
				f[j]=1;
				yojo++;
			}
		}
		if(yojo<k)continue;
		ll ma=a[0],cnt=0;
		for(int j=1;j<n;j++){
			if(f[j]&&a[j]<=ma){
				cnt+=ma-a[j]+1;
				ma++;
			}
			if(a[j]>ma)ma=a[j];
		}
		ans=min(ans,cnt);
	}
	cout<<ans<<endl;
	return 0;
}
