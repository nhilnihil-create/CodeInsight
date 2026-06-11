#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int main(){
	string s;
	cin>>s;
	ll cnt=s.size();
	cout<<(cnt%2==(s[0]==s[s.size()-1])?"Second":"First");
	return 0;
}