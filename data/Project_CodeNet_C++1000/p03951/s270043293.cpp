#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

//#include "atcoder/all"
//using namespace atcoder;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	string s, t;
	cin >> n >> s >> t;
	rep(i,n){
		bool ok = true;
		for(int j = i; j < n; ++j){
			if(s[j] != t[j-i]) ok = false;
		}
		if(ok){
			cout << n+i << endl;
			return 0;
		}
	}
	cout << 2*n << endl;
	return 0;
}