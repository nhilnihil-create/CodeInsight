#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, int> LP;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll a, b, c;
	cin >> a >> b >> c;
	ll ans = llabs(a*b*(c/2) - a*b*(c - c/2));
	chmin(ans, llabs(a*(b/2)*c - a*(b - b/2)*c));
	chmin(ans, llabs((a/2)*b*c - (a - a/2)*b*c));
	cout << ans << endl;
	return 0;
}