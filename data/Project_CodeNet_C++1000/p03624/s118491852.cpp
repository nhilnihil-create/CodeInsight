#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

bool used[26];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	rep(i,s.size()){
		used[(s[i]-'a')] = true;
	}
	rep(i,26){
		if(!used[i]){
			char ans = 'a' + i;
			cout << ans << endl;
			return 0;
		}
	}
	cout << "None" << endl;
	return 0;
}
