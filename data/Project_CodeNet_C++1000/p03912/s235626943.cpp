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
	vector<int> a(100001, 0);
	rep(i,n){
		int x;
		cin >> x;
		a[x]++;
	}
	int ans = 0;
	rep(i,m){
		int j = (m-i)%m;
		if(i == j){
			int s = 0;
			for(int k = i; k < 100001; k += m) s += a[k];
			ans += s/2;
		}
		else if(i < j){
			int s = 0, sx = 0;
			for(int k = i; k < 100001; k += m) s += a[k]/2*2, sx += a[k] & 1;
			int t = 0, tx = 0;
			for(int k = j; k < 100001; k += m) t += a[k]/2*2, tx += a[k] & 1;
			if(sx > tx){
				swap(s, t);
				swap(sx, tx);
			}
			ans += sx;
			tx -= sx;
			int x = min(tx, s);
			ans += x;
			s -= x;
			ans += s/2;
			ans += t/2;
		}
	}
	cout << ans << endl;
	return 0;
}