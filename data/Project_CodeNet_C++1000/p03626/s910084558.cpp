#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int M = 1e9+7;

int main(){
	int n;
	cin>>n;

	string s1;
	string s2;
	cin>>s1;
	cin>>s2;

	bool x = 0;
	bool y = 0;
	ll ans = 1;
	int idx = 0;
	if(s1[0]!=s2[0]){
	 idx+=2;
	 ans = 6;
	 y = 1;
	}
	else{
	x = 1;
	idx+=1;
	 ans = 3;
	}

	while(idx<n){
		if(s1[idx]!=s2[idx] && y){
			ans*=3%M;
			idx+=2;
		}
		else if(s1[idx] == s2[idx] && y){
			y = 0;
			x = 1;
			ans*=1%M;
			idx+=1;
		}
		else if(s1[idx]!=s2[idx] && x){
			y = 1;
			x = 0;
			ans*=2%M;
			idx+=2;
		}
		else if(s1[idx]==s2[idx] && x){
			ans*=2%M;
			idx+=1;
		}
	}
	cout<<ans%M;
}