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
	int n;
	string s;
	cin >> n >> s;
	int ans = 0, cnt = 0;
	rep(i,n){
		if(s[i] == '(') ++cnt;
		else{
			if(cnt > 0) --cnt;
			else ++ans;
		}
	}
	rep(i,ans) cout << "(";
	cout << s;
	rep(i,cnt) cout << ")";
	cout << endl;
	return 0;
}