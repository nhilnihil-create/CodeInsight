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
	rep(i,h*w){
		char a;
		cin >> a;
		++mp[a];
	}
	int two = 0, four = 0;
	for(auto p : mp){
		four += p.second / 4;
		p.second %= 4;
		two += p.second / 2;
	}
	int n_four = (h/2) * (w/2);
	int n_two = (h*w - n_four * 4) / 2;
	bool ok = true;
	if(four < n_four) ok = false;
	two += (four - n_four) * 2;
	if(two < n_two) ok = false;
	cout << (ok ? "Yes" : "No") << endl;
	return 0;
}
