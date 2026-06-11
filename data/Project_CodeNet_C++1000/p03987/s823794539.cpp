#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<ll> a(n);
	rep(i,n){
		int b;
		cin >> b;
		--b;
		a[b] = i;
	}
	set<ll> st;
	st.insert(-1);
	st.insert(n);
	ll ans = 0;
	rep(i,n){
		auto idx = st.lower_bound(a[i]);
		ll r = *idx;
		ll l = *(--idx);
		ans += (i+1) * (a[i] - l) * (r - a[i]);
		st.insert(a[i]);
	}
	cout << ans << endl;
	return 0;
}
