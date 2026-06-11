#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll a[114514],t[114514];
bool f[114514];
int main(){
	ll n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>t[i];
	for(int i=0;i<n;i++)cin>>a[i];
	ll mod=1e9+7,ans=1;
	if(a[0]!=t[n-1]){
		cout<<0;
		return 0;
	}
	for(int i=1;i<n;i++){
		if(t[i-1]<t[i]){
			f[i]=1;
			if(t[i]>a[i]){
				cout<<0;
				return 0;
			}
		}
	}
	for(int i=n-2;i>=0;i--){
		if(a[i+1]<a[i]){
			f[i]=1;
			if(t[i]<a[i]){
				cout<<0;
				return 0;
			}
		}
	}

	f[0]=f[n-1]=1;
	for(int i=0;i<n;i++){
		//cout<<f[i]<<' ';
		if(f[i])continue;
		ans*=min(a[i],t[i]);
		ans%=mod;
	}
	cout<<ans;
	return 0;
}
