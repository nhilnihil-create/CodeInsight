#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	string s;
	cin>>s;
	map<char,ll>a;
	for(ll i=0;i<s.size();i++){
		char now=s[i];
		a[now]++;
	}
	ll n=s.size()*(s.size()-1)/2;
	ll k1=0;
	for(auto itr=a.begin();itr!=a.end();itr++){
		ll val=itr->second;
		k1+=val*(val-1)/2;
	}
	cout << 1+n-k1;
	// your code goes here
	return 0;
}