#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 

int main() {
	ll n,mi=1;
	cin>>n;
	ll ans=0;
	for(ll i=0;i<n;i++){
		ll now;
		cin>>now;
		if(now==mi){
			mi++;
			continue;
		}
		if(now%mi!=0){
			ans+=now/mi;
		}
		else{
			ans+=(now-1)/mi;
		}
		if(mi==1){
			mi++;
		}
		//cout << i <<" "<<mi<<" "<<ans<<endl;
	}
	cout <<ans;
	// your code goes here
	return 0;
}