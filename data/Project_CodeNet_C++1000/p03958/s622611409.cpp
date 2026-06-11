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
	int mx = 0;
	rep(i,t){
		int a;
		cin >> a;
		chmax(mx, a);
	}
	int ans = 0, oth = k - mx;
	bool flag = false;
	rep(i,k){
		if(i%2 == 0){
			if(mx <= 0){
				cout << 0 << endl;
				return 0;
			}
			--mx;
		}
		else{
			if(oth <= 0){
				cout << mx << endl;
				return 0;
			}
			--oth;
		}
	}
	cout << mx << endl;
	return 0;
}