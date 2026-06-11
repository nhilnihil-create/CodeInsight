#include <bits/stdc++.h>
#define INF (1<<30)
#define MOD 1000000007
#define l_ength size
using ll = long long;
using namespace std;

int yes(){
	cout << "YES" << endl;
	return 0;
}

int no(){
	cout << "NO" << endl;
	return 0;
}

int main(){
	ll n; cin >> n;
	vector<ll> a(n);
	for( auto &k : a ) cin >> k;
	ll acc = accumulate( a.begin(), a.end(), 0ll );
	ll sum = (n*(n+1))/2;
	if( acc % sum != 0 ) return no();
	ll k = acc / sum;
	vector<ll> d(n);
	for( int i = 0; i < n; ++i ){
		if( i == n-1 ){
			d[i] = a[0] - a[i];
		} else {
			d[i] = a[i+1] - a[i];
		}
	}
	ll ycnt = 0;
	for( auto p : d ){
		if(
			(k-p)%n != 0 || ((n-1)*k+p)%n != 0
			||
			(k-p)/n < 0 || ((n-1)*k+p)/n < 0
			||
			(k-p)/n + ((n-1)*k+p)/n != k
		){
			return no();
		}
		ycnt += (k-p)/n;
	}
	( ycnt == k ) ? yes() : no();
	return 0;
}