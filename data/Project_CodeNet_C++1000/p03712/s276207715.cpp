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
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	rep(i,h) cin >> s[i];
	rep(j,w+2) cout << "#";
	cout << endl;
	rep(i,h){
		cout << "#" << s[i] << "#" << endl;
	}
	rep(j,w+2) cout << "#";
	cout << endl;
	return 0;
}