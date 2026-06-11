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
	vector<int> cnt(100005, 0);
	int n;
	cin >> n;
	rep(i,n){
		int a;
		cin >> a;
		++cnt[a+2];
		++cnt[a+1];
		++cnt[a];
	}
	int ans = 0;
	rep(i,100003) chmax(ans, cnt[i]);
	cout << ans << endl;
	return 0;
}