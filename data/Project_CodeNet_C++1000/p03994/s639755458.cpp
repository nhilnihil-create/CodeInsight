#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	string s;
	cin>>s;
	ll n;
	cin>>n;
	for(ll i=0;i<s.size();i++){
		if(s[i]=='a'){
			continue;
		}
		else if('z'-s[i]+1<=n){
			n-='z'-s[i]+1;
			s[i]='a';
		}
	}
	for(ll i=s.size()-1;i>=0;i--){
		if(s[i]=='a'){
			continue;
		}
		else{
			s[i]=s[i]+n;
			n=0;
			break;
		}
	}
	if(n!=0){
		n%=26;
		s[s.size()-1]=s[s.size()-1]+n;
	}
	cout <<s;
	// your code goes here
	return 0;
}