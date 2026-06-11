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
	string s;
	cin >> s;
	int n = s.size();
	map<char, ll> cnt;
	ll ans = 0;
	for(int i = n-1; i >= 0; i--){
		ans += n - 1 - i - cnt[s[i]];
		cnt[s[i]]++;
	}
	ans++;
	cout << ans << endl;
	return 0;
}
