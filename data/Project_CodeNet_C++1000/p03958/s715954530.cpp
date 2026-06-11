#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rall(x) (x).rbegin(),(x).rend()

int main(){
	int k,t; cin>>k>>t;
	vector<int> v(t);
	rep(i,t) cin>>v[i];
	sort(rall(v));
	int cnt=0;
	for(int i=1; i<t; i++) cnt+=v[i];
	int ans=v[0]-cnt-1;
	if(ans<=0) cout<<0<<endl;
	else cout<<ans<<endl;
}