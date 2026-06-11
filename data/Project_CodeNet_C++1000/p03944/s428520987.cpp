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
	int r, u, l = 0, d = 0, n;
	cin >> r >> u >> n;
	rep(i,n){
		int x, y, a;
		cin >> x >> y >> a;
		if(a == 1){
			chmax(l, x);
		}
		if(a == 2){
			chmin(r, x);
		}
		if(a == 3){
			chmax(d, y);
		}
		if(a == 4){
			chmin(u, y);
		}
	}
	int ans = max(r-l, 0) * max(u-d, 0);
	cout << ans << endl;
	return 0;
}