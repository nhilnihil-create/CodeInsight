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
	int h, w;
	cin >> h >> w;
	map<char, int> mp;
	rep(i,h)rep(j,w){
		char c;
		cin >> c;
		++mp[c];
	}
	int four = (h/2) * (w/2);
	int two = (h*w - four * 4) / 2;
	int f = 0, t = 0;
	for(auto p : mp){
		f += p.second / 4;
		p.second %= 4;
		t += p.second / 2;
	}
	if(f < four){
		cout << "No" << endl;
		return 0;
	}
	t += (f - four) * 2;
	if(t < two) cout << "No" << endl;
	else cout << "Yes" << endl;
	return 0;
}
