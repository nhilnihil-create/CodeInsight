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
	bool n = false, w = false, S = false, e = false;
	string s;
	cin >> s;
	rep(i,s.size()){
		if(s[i] == 'N') n = true;
		if(s[i] == 'W') w = true;
		if(s[i] == 'S') S = true;
		if(s[i] == 'E') e = true;
	}
	if(n^S || w^e) cout << "No" << endl;
	else cout << "Yes" << endl;
	return 0;
}