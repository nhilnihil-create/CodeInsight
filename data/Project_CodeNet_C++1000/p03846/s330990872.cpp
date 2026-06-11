#include<bits/stdc++.h>
using namespace std;

#define deb(x) cerr<<"["#x<<" : "<<x<<" ]\n";

using ll = long long;
const ll MOD = 1e9+7 ;
 
ll power( ll base, ll exp ) {	
	if( exp == 0 ) {
		return 1ll ;
	}
 
	ll mid = power(base,exp/2)%MOD ;
	
	return ((mid*mid)%MOD*(( exp&1 ? base : 1 )%MOD))%MOD ;
}
 

int main()
{
	int n ;
	cin >> n ;
 
	bool parity = n%2 ;
 
	vector<int> v(n);
	map<int,int> cnt ;
	
	for( int i = 0 ; i < n ; ++i ) {
		cin >> v[i];
		cnt[v[i]]++;
		if( (v[i]&1) == parity ) {
			cout << 0;
			return 0;
		}
	}
 
	if( (parity && cnt[0] != 1) || (!parity && cnt[0]) ) {
		cout << 0;
		return 0;
	}
 
	for( int d : v ) {
		if( !d ) {
			continue;
		}
		if( cnt[d] > 2 || cnt[d] < 2 ) {
			cout << 0;
			return 0;
		}
	}
 
	cout << power(2ll,n/2);
}
