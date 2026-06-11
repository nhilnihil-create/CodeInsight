#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll INF = 1e18;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	ll x;
	cin >> n >> x;
	vector<ll> a(n);
	vector<vector<ll>> b(n, vector<ll>(n, INF));
	rep(i,n) cin >> a[i];
	rep(i,n){
		b[i][0] = a[i];
		for(int j = 1; j < n; ++j){
			int nj = (n + i - j) % n;
			b[i][j] = min(b[i][j-1], a[nj]);
		}
	}
	ll ans = INF;
	rep(j,n){
		ll cost = x * j;
		rep(i,n){
			cost += b[i][j];
		}
		chmin(ans, cost);
	}
	cout << ans << endl;
	return 0;
}