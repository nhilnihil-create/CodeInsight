#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,n;
ll N = 1e5+5;
vector<ll> arr(N);

bool ok(ll t){
	ll t1=t;
	for(int i=0;i<n;i++){
		if((arr[i]-(b*t1)) <=0){
			continue;
		}

			t =t- (arr[i]-(b*t1)+a-b-1)/(a-b);
	
			if(t<0){
				return 0;
			}
		

	}
	return 1;
	
}
int main(){
	cin>>n>>a>>b;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	ll l,r;
	l =1;
	r = *max_element(arr.begin(),arr.begin()+n);
	ll ans ;
	while(l<=r){
		ll mid = l+(r-l)/2;
		//cout<<mid<<"ok"<<l<<"ok"<<r<<endl;
		if(ok(mid)){
			r = mid-1;
			ans = mid;
		}
		else{
			l = mid+1;
		}
	}
	cout<<ans<<endl;
	
}