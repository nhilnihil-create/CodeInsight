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
	int n;
	cin >> n;
	vector<ll> a(n), b(n);
	rep(i,n) cin >> a[i] >> b[i];
	ll ans = 0, cnt = 0;
	for(int i = n-1; i >= 0; i--){
		if((a[i]+cnt)%b[i] == 0) continue;
		ll dif = b[i] - ((a[i]+cnt)%b[i]);
		ans += dif;
		cnt += dif;
	}
	cout << ans << endl;
	return 0;
}