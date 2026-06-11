#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll q, h, s, d, n;
	cin >> q >> h >> s >> d >> n;
	ll ans = q * n * 4;
	chmin(ans, h*n*2);
	chmin(ans, s*n);
	chmin(ans, (n/2)*d + (n%2)*min({q*4,h*2,s}));
	cout << ans << endl;
	return 0;
}