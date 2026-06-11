#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

int main(){
	int n; string s,t; cin>>n>>s>>t;
	string s1,t1;
	int cnt=0;
	rep(i,n){
		s1=s.substr(i,n), t1=t.substr(0,n-i);
		if(s1==t1) {cnt=s1.size(); break;}
	}
	cout<<2*n-cnt<<endl;
}