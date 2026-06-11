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
	int n;
	ll k;
	cin >> n >> k;
	vector<ll> a(n), b(n);
	rep(i,n) cin >> a[i] >> b[i];
	ll two = 1, ans = 0, score = 0;
	int r = 0;
	rep(i,n){
		bool ok = true;
		rep(j,32){
			if(a[i]>>j & 1){
				if(!(k>>j & 1)) ok = false;
			}
		}
		if(ok) score += b[i];
	}
	chmax(ans, score);
	while(two <= k){
		ll ki = k;
		if(ki>>r & 1){
			ki /= two;
			ki *= two;
			ki -= 1;
		}
		//cout << r << " " << two << " " << ki << endl;
		score = 0;
		rep(i,n){
			bool ok = true;
			rep(j,32){
				if(a[i]>>j & 1){
					if(!(ki>>j & 1)) ok = false;
				}
			}
			if(ok) score += b[i];
		}
		chmax(ans, score);
		++r;
		two *= 2;
	}
	cout << ans << endl;
	return 0;
}