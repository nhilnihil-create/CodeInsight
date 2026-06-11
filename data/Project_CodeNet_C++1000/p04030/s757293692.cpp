#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	string s; cin>>s;
	string ans;
	rep(i,s.size()){
		if(s[i]=='0') ans+='0';
		else if(s[i]=='1') ans+='1';
		else if(ans.size()!=0&&s[i]=='B') ans.erase(ans.size()-1);
	}
	cout<<ans<<endl;
}