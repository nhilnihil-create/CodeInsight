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
	cin >> n;
	int mx = 0, mi = 1e9;
	vector<int> a(n);
	map<int, int> mp;
	rep(i,n){
		cin >> a[i];
		chmax(mx, a[i]);
		chmin(mi, a[i]);
		++mp[a[i]];
	}
	if(mx - mi > 1){
		cout << "No" << endl;
		return 0;
	}
	if(mx == mi){
		if(mx == n-1 || 2*mx <= n) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	else{
		if(2*mx <= 2*mp[mi] + mp[mx] && mp[mi] < mx) cout << "Yes" << endl;
		else cout << "No" << endl; 
	}
	return 0;
}