#include <bits/stdc++.h>
#define l_ength size
const int inf = (1<<30);
const int mod = 1000000007;
using ll = long long;
using namespace std;

int main(){
	int n; ll a, b; cin >> n >> a >> b;
	vector<ll> x(n);
	for( auto &k : x ) cin >> k;
	ll sum = 0;
	for( int i = 0; i < n-1; ++i ){
		ll d = x[i+1]-x[i];
		sum += min(a*d, b);
	}
	cout << sum << endl;
}