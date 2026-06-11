#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	string s; cin>>s;
	vector<char> ns={'P'};
	vector<char> ew={'P'};
	int k=s.size();
	rep(i,k){
		if(s[i]=='N') ns.push_back('N');
		if(s[i]=='S') ns.push_back('S');
		if(s[i]=='E') ew.push_back('E');
		if(s[i]=='W') ew.push_back('W');
	}
  
	if(ns.size()==2||ew.size()==2) {cout<<"No"<<endl; return 0;}
	bool bns=false, bew=false;
	if(ns[ns.size()-2]!=ns[ns.size()-1]) bns=true;
	if(ew[ew.size()-2]!=ew[ew.size()-1]) bew=true;
	if(bns&&bew) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}