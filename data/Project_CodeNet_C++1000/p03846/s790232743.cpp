#include<bits/stdc++.h>
#define fuckit(){	\
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL); \
}
using namespace std;
typedef long long ll;
int net[100000+10];
int main()
{
	fuckit();
	ll n,i,t=2;
	cin>>n;
	int ara[n];
	for(i=0;i<n;i++){
		cin>>ara[i];
		net[ara[i]]++;
	}
	if(n<=2){
		if(n==1){
			if(ara[0]==0){
			cout<<1<<endl;
			return 0;
			}
			else{
			cout<<0<<endl;
			return 0;
			}
		}
		else{
			if(ara[0]==1==ara[1]){
				cout<<2<<endl;
				return 0;
			}
			else{
				cout<<0<<endl;
				return 0;
			}
		}
	}
	if(n%2){
	if(net[0]!=1){
		cout<<0<<endl;
		return 0;
	}
	}
	for(i=1;i<=n;i+=2){
		if(net[i-n%2]!=2&&(i-n%2)!=0){
			cout<<0<<endl;
			return 0;
		}
	}
	ll ans=1;
	for(i=1;i<=n/2;i++){
		ans*=2;
		ans%=1000000007;
	}
	cout<<ans<<endl;
	return 0;	
}