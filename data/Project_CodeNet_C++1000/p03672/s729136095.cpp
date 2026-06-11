#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fast ios::sync_with_stdio(false); cin.tie(NULL);
#define loop(n) for(int i=0; i<n; i++)
#define rep(i,start,n) for(int i=start; i<n; i++)
bool check(string s,int n){
	int mid = n/2;
	int st = 0;
	while(st!=n/2){
		if(s[st]!=s[mid])return 0;
		st++;
		mid++;
	}
	return 1;
}
void solve(){
	string s;cin >> s;
	int n = s.length();

	if(n%2!=0)n--;

	while( n>2 ){
		n-=2;
		// cout<<n<<endl;		
		if(check(s,n)){
			cout<<n;
			return;
		}
	}	
	cout<<n<<endl;
}	
signed main(){
    fast;    
    // int t;cin>>t;while(t--)
    solve();    
    return 0;
}
