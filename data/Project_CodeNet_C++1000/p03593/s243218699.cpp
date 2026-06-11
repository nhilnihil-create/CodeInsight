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
	char c;
	map<char, int> cnt;
	rep(i,h)rep(j,w){
		cin >> c;
		cnt[c]++;
	}
	int two = 0, four = 0;
	for(auto p : cnt){
		four += p.second / 4;
		p.second %= 4;
		two += p.second / 2;
		p.second %= 2;
	}
	bool yes = true;
	if(four < (h/2)*(w/2)) yes = false;
	else four -= (h/2)*(w/2);
	two += four*2;
	if(two < ((h*w) - (h/2)*(w/2)*4)/2) yes = false;
	cout << (yes ? "Yes" : "No") << endl;
	return 0;
}
