#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	string s; cin>>s;
	int k=s.size();
	set<char> st;
	rep(i,k) st.insert(s[i]);
  
	if(st.size()==k) cout<<"yes"<<endl;
	else cout<<"no"<<endl;
}