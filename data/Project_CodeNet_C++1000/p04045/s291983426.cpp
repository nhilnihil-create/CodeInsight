#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=1e9+7;
template <class Q>
void clearQueue(Q & q) {
    q = Q();
}
void solve(){
    int n,k;cin>>n>>k;
    map<int,bool>mp;
    for(int i=1;i<=k;i++){
        int x;
        cin>>x;
        mp[x]=true;
    }
    for(int i=n;;i++){
        string s=to_string(i);
        bool flag=true;
        for(int j=0;j<s.length();j++){
            if(mp[s[j]-'0']==true) {flag=false;break;}
        }
        if(flag) {cout<<i;break;}
    }
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
