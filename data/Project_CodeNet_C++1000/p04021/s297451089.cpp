#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
 
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	rep(i, n){
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b.begin(), b.end());
	int ans = 0;
	rep(i, n){
		int idx = lower_bound(b.begin(), b.end(), a[i])-b.begin();
		if(i%2 != idx%2) ans++;
	}
	cout << ans/2 << endl;
	return 0;
}