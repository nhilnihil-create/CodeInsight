#include<bits/stdc++.h>
#define ll long long
#define all(a) a.begin(),a.end()
#define sz(a) a.size()
#define re return 
#define MP make_pair
#define pb push_back
#define pii pair<int,int>
#define se second
#define fi first
using namespace std;
string s,ans;
signed main(){
	ios_base::sync_with_stdio(0);
	cin>>s;
	ans="";
	for(int i=0;i<sz(s);i++){
		if(s[i]!='B') ans+=s[i];
		else if(sz(ans)) ans=ans.substr(0,sz(ans)-1);
	}
	cout<<ans;
	re 0;
}