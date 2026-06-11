#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
int n,a[111111],b[111111],ans=1;
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++){
		if((a[i]>a[i-1]&&b[i]<a[i])||(b[i]>b[i+1]&&b[i]>a[i]))ans=0;
		else if(a[i]==a[i-1]&&b[i]==b[i+1]){
			ans*=min(a[i],b[i]);
			ans%=mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}