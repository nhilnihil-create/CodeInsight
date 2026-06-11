#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll INF = 1e18;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	ll x;
	cin >> n >> x;
	vector<ll> a(2*n);
	rep(i,n){
		cin >> a[i];
		a[i+n] = a[i];
	}
	vector<vector<ll>> mi(n, vector<ll>(n, INF));
	rep(i,n){
		rep(j,n){
			mi[i][j] = min(mi[i][max(0,j-1)], a[i+n-j]);
		}
	}
	ll ans = 1e18;
	rep(i,n){
		ll cost = x * i;
		rep(j,n){
			cost += mi[j][i];
		}
		chmin(ans, cost);
	}
	cout << ans << endl;
	return 0;
}