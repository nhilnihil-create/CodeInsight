#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=1e9+7;
template <class Q>
void clearQueue(Q & q) {
    q = Q();
}
void solve(){
    int n,l;cin>>n>>l;
    vector<string>v(n);
    for(int i=1;i<=n;i++){
        cin>>v[i-1];
    }
    sort(v.begin(),v.end());
    for(auto x:v) cout<<x;
    
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL); 
	int T=1;
	// cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
