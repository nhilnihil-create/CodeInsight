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
	int n, m;
	cin >> n >> m;
	vector<ll> a(n), b(n), c(m), d(m);
	rep(i,n) cin >> a[i] >> b[i];
	rep(i,m) cin >> c[i] >> d[i];
	rep(i,n){
		ll mindist = 1e18;
		int idx = 0;
		rep(j,m){
			ll dist = llabs(a[i] - c[j]) + llabs(b[i] - d[j]);
			if(dist < mindist){
				mindist = dist;
				idx = j+1;
			}
		}
		cout << idx << endl;
	}
	return 0;
}
