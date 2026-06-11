#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld double
#define ff first
#define ss second
ll mod = 1000000007;
void fun(){
	string s; cin>>s;
	int ans=0;
	for(int i=1;i<(int)s.length();++i){
		if(s[i]!=s[i-1]) ++ans; 
	}
	cout<<ans<<"\n";
	return;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1; //cin>>t;
	while(t--){
		fun();
	}
	return 0;
}

