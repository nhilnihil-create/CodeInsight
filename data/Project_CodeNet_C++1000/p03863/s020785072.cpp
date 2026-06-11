#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef long double ld;
#define pb push_back
#define fi first
#define se second
const ll mod = 1e9+7;
const int N = 2e5+5;
void solve(){
	string s; 
	cin>>s; 
	int n = s.size();
	if(s[0]==s[n-1])n--;
	if(n%2)cout<<"First"<<endl;
	else cout<<"Second"<<endl;
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
