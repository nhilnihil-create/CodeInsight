#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	string s; cin>>s;
	int k=s.size();
	while(1){
		s.erase(k-2,2);
		k=s.size();
		string s1=s.substr(0,k/2);
		string s2=s.substr(k/2,k/2);
		if(s1==s2){cout<<s.size()<<endl; return 0;}
	}
}