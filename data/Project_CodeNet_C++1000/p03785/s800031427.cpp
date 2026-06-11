#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll INF = 2e9;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n, c, k;
	cin >> n >> c >> k;
	vector<ll> t(n);
	rep(i,n) cin >> t[i];
	sort(t.begin(), t.end());
	ll time = 0, cnt = 0, ans = 0;
	rep(i,n){
		if(cnt == 0){
			++ans;
			cnt = c - 1;
			time = t[i] + k;
		}
		else --cnt;
		if(time < t[i]){
			++ans;
			cnt = c - 1;
			time = t[i] + k;
		}
	}
	cout << ans << endl;
	return 0;
}