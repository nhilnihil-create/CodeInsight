#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<ll> a(n);
	ll inner = 0, outer = 0;
	rep(i,n){
		cin >> a[i];
		if(i < k) inner += a[i];
		else{
			if(a[i] > 0) outer += a[i];
		}
	}
	ll ans = 0;
	chmax(ans, inner + outer);
	for(int i = k; i < n; ++i){
		inner -= a[i-k];
		inner += a[i];
		if(a[i-k] > 0) outer += a[i-k];
		if(a[i] > 0) outer -= a[i];
		chmax(ans, max(inner, 0LL) + outer); 
	}
	cout << ans << endl;
	return 0;
}
