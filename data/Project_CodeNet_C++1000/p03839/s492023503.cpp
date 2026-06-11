#include <bits/stdc++.h>
#define INF (1<<30)
#define MOD 1000000007
#define l_ength size
using ll = long long;
using namespace std;

int main(){
	int n, k; cin >> n >> k;
	vector<ll> a(n);
	for( auto &k : a ) cin >> k;
	vector<ll> sp(n+1);
	sp[0] = 0;
	for( int i = 0; i < n; ++i ){
		sp[i+1] = sp[i];
		if( a[i] > 0 ) sp[i+1] += a[i];
	}
	vector<ll> sm(n+1);
	sm[0] = 0;
	for( int i = 0; i < n; ++i ){
		sm[i+1] = sm[i];
		if( a[i] < 0 ) sm[i+1] += a[i];
		/*
		まちがい: if( a[i] < 0 ) sm[i+1] = sm[i] + a[i];
		これは a[i] >= 0 のときに sm が更新されなくなって RE を吐く
		*/
	}
	ll opt = sp[n];
	ll ans = 0;
	for( int i = 0; i+k <= n; ++i ){
		ans = max( { ans, opt-(sp[i+k]-sp[i]), opt+(sm[i+k]-sm[i]) } );
	}
	cout << ans << endl;
	return 0;
}