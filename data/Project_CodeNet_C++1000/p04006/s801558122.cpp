#include <bits/stdc++.h>
#define l_ength size
const int inf = (1<<30);
const int mod = 1000000007;
using ll = long long;
const ll infll = (1ll<<60);
using namespace std;

const int bound = 2019;
int n;
vector<ll> a;
ll mini[bound][bound];

void init(){
	for( int i = 0; i < n; ++i ){
		mini[i][i] = inf;
		for( int j = i; j < n; ++j ){
			mini[i][j+1] = min(mini[i][j], a[j]);
		}
	}
}

ll query( int a, int b ){
	if( a < 0 ){
		return min(mini[n+a][n], mini[0][b]);
	} else
		return mini[a][b];
}

int main(){
	ll x; cin >> n >> x;
	for( int i = 0; i < n; ++i ){
		ll tmp; cin >> tmp;
		a.push_back(tmp);
	}
	init();
	ll ans = infll;
	for( int k = 0; k < n; ++k ){
		ll res = 0;
		for( int i = 0; i < n; ++i ){
			res += query(i-k, i+1);
		}
		ans = min(ans, res+k*x);
	}
	cout << ans << endl;
}