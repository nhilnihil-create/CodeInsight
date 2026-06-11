#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	string s;
	cin>>s;
	map<char, int> mp;
	for(auto ch : s){
		mp[ch]++;
	}
	if(mp['N'] > 0 && mp['S'] == 0)cout<<"No"<<'\n';
	else if(mp['S'] > 0 && mp['N'] == 0)cout<<"No"<<'\n';
	else if(mp['E'] > 0 && mp['W'] == 0)cout<<"No"<<'\n';
	else if(mp['W'] > 0 && mp['E'] == 0)cout<<"No"<<'\n';
	else cout<<"Yes"<<'\n';

	return 0;
}