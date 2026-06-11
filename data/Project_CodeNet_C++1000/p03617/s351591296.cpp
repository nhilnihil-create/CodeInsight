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
	ll q, h, s, d, n;
	cin >> q >> h >> s >> d >> n;
	ll cost_per = 1e9;
	if(cost_per > q*4){
		cost_per = q*4;
	}
	if(cost_per > h*2){
		cost_per = h*2;
	}
	if(cost_per > s){
		cost_per = s;
	}
	ll ans;
	if(cost_per > d/2){
		if(n%2 == 0) ans = d * (n/2);
		else ans = d * (n/2) + cost_per;
	}
	else{
		ans = cost_per * n;
	}
	cout << ans << endl;
	return 0;
}