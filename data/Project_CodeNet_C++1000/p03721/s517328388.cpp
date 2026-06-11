#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1000000000000000000
#define mod 1000000007

int main(){
	ll n,k;cin>>n>>k;
	vector<pair<ll,ll>> P(n);

	for(ll i=0;i<n;i++){
		ll a,b;
		cin>>a>>b;

		P[i]=make_pair(a,b);
	}

	sort(P.begin(),P.end());

	ll num=0,i=0,ans;
	while(num<k){
		num+=P[i].second;
		if(num>=k){ans=P[i].first;}
		i++;
	}

	cout<<ans<<endl;
	return 0;
}