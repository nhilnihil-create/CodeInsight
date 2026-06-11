#include <bits/stdc++.h>

#define ll long long 
#define sz(x) (int)x.size()

using namespace std;

bool ok(string s){
	if(sz(s)&1)return false;
	string t="",g="";
	for(int i=0;i<sz(s)/2;i++){
		t+=s[i];
	}
	for(int i=sz(s)/2;i<sz(s);i++){
		g+=s[i];
	}
	return t==g;
}
int ans;

int main(){
	string s;
	cin>>s;
	string t="";
	for(int i=0;i<sz(s)-1;i++){
		t+=s[i];
		if(ok(t)){
			ans=sz(t);
		}
	}
	cout<<ans;
}



