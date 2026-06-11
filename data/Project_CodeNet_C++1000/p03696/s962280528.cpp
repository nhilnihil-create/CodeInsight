#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i,n) for(ll i=0;i<n;i++)

int main(){
	int n;cin>>n;
	string s;cin>>s;
	int l[n+1]={},r[n+1]={};

	rep(i,n){
		if(s[i]=='(') l[i+1]=l[i]+1;
		else l[i+1]=max(0,l[i]-1);
	}

	for(int i=n-1;i>=0;i--){
		if(s[i]==')') r[i]=r[i+1]+1;
		else r[i]=max(r[i+1]-1,0);
	}
/*
	rep(i,n+1) cout<<l[i]<<" ";
	cout<<"\n";

	rep(i,n+1) cout<<r[i]<<" ";
	cout<<"\n";
*/
	while(r[0]){
		cout<<'(';
		r[0]--;
	}
	cout<<s;
	while(l[n]){
		cout<<')';
		l[n]--;
	}
	cout<<"\n";

}