#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	string S; cin>>S;
	string ans; ans+=S[0];
	ans+=to_string(S.size()-2);
	ans+=S[S.size()-1];
	cout<<ans<<endl;
}