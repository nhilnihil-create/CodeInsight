#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	fastio
	string s;
	cin>>s;
	cout<<s[0]<<s.size()-2<<s[s.size()-1];
	return 0;
}