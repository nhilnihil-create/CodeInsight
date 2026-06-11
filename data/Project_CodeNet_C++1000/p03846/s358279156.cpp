#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100005];
ll ans=1;
ll c[100005];
int main(void){
	ll n; cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		c[a[i]]++;
	}
	if(n%2==0){
		for(int i=1;i<=n-1;i=i+2){
			if(c[i]!=2){
				cout<<0<<endl;
				return 0;
			}
			ans=(ans*2)%1000000007;
		}
		
	}else{
		for(int i=0;i<=n-1;i=i+2){
			if(i==0){
				if(c[i]!=1){
					cout<<0<<endl;
					return 0;
				}
			}else{
				if(c[i]!=2){
					cout<<0<<endl;
					return 0;
				}
			}
			ans=(ans*2)%1000000007;
		}
		ans=ans/2;
	}
	cout<<ans<<endl;  
}
