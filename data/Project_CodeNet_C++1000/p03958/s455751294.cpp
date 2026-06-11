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
	int k, t;
	cin >> k >> t;
	ll sum = 0, mx = 0;
	rep(i,t){
		ll a;
		cin >> a;
		chmax(mx, a);
		sum += a;
	}
	if(mx*2 <= sum) cout << 0 << endl;
	else{
		cout << mx*2 - sum - 1 << endl;
	}
	return 0;
}