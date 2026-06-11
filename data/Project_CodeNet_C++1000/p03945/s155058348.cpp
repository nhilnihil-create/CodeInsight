#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
#define pb push_back
#define fi first
#define se second
const ll mod = 1e9+7;
const int N = 1e5+6;
void solve(){
	string s; 
	cin>>s; 
	int ans = 0;
	int n= s.size();
	for(int i=1;i<n;i++){
		if(s[i]!=s[i-1])ans++;
	}
	cout<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t=1; 
//	cin>>t; 
	while(t--){
		solve();
	}
	return 0;
}
