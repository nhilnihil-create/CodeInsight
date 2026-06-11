#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	ll c, k;
	cin >> n >> c >> k;
	vector<ll> t(n);
	rep(i,n) cin >> t[i];
	sort(t.begin(), t.end());
	int ans = 0;
	ll cap = 0, bus_time = 0;
	rep(i,n){
		if(cap == 0){
			++ans;
			cap = c - 1;
			bus_time = t[i] + k;
		}
		else --cap;
		if(bus_time < t[i]){
			++ans;
			cap = c - 1;
			bus_time = t[i] + k;
		}
	}
	cout << ans << endl;
	return 0;
}