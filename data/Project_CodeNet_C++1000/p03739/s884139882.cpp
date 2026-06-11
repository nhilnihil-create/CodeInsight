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
	vector<ll> a(n);
	rep(i,n) cin >> a[i];
	ll ans1 = 0, sum1 = 0;
	rep(i,n){
		sum1 += a[i];
		if(i%2 == 1){
			if(sum1 >= 0){
				ans1 += 1 + sum1;
				sum1 = -1;
			}
		}
		else{
			if(sum1 <= 0){
				ans1 += 1 - sum1;
				sum1 = 1;
			}
		}
	}
	ll ans2 = 0, sum2 = 0;
	rep(i,n){
		sum2 += a[i];
		if(i%2 == 1){
			if(sum2 <= 0){
				ans2 += 1 - sum2;
				sum2 = 1;
			}
		}
		else{
			if(sum2 >= 0){
				ans2 += 1 + sum2;
				sum2 = -1;
			}
		}
	}
	ll ans = min(ans1, ans2);
	cout << ans << endl;
	return 0;
}
