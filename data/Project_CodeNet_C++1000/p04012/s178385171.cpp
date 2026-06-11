#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	string s; cin>>s;
	int k=s.size();
	
	map<char,int> mp;
	rep(i,k){
		mp[s[i]]++;
	}
	bool flg=true;
	for(auto x:mp) if(x.second%2!=0) flg=false;
	cout<<(flg?"Yes":"No")<<endl;
}