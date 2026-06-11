#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int n,t;cin>>n>>t;
	vector<int> a(n),mx(n),mn(n);

	for(auto&& w:a)cin>>w;
	copy(begin(a),end(a),begin(mn));
	copy(begin(a),end(a),begin(mx));

	for(int i=0;i<n-1;i++){
		mn[i+1]=min(mn[i+1],mn[i]);
	}
	for(int i=n-1;i>=1;i--){
		mx[i-1]=max(mx[i-1],mx[i]);
	}
	int maxval=0ll,cnt=0ll,minval=-1ll;
	for(int i=0;i<n;i++){
		maxval=max(maxval,mx[i]-mn[i]);
	}
	for(int i=0;i<n;i++){
		if(maxval!=mx[i]-mn[i])continue;
		if(minval!=mn[i]){
		cnt++;minval=mn[i];	
		}
	}
	if(t<2)cout<<0<<endl;
	else cout<<cnt<<endl;

}