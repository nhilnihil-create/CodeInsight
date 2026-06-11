#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	map<int, int> mp;
	rep(i,n){
		int a;
		cin >> a;
		mp[a]++;
		mp[a-1]++;
		mp[a+1]++;
	}
	int ans = 0;
	for(auto p : mp){
		chmax(ans, p.second);
	}
	cout << ans << endl;
	return 0;
}