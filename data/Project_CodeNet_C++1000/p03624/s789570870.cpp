#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	string s; cin>>s;
	set<char> st;
	for(int i=0; i<26; i++){
		char t='a'+i;
		st.insert(t);
	}
	int k=s.size();
	rep(i,k){
		st.erase(s[i]);
	}
	if(st.size()==0) cout<<"None"<<endl;
	else cout<<*st.begin()<<endl;
	
}
