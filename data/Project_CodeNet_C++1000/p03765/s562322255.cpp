#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define ep emplace_back
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)
constexpr int mod=1000000007;
constexpr int mod1=998244353;
vector<int> dx={0,1,0,-1},dy={-1,0,1,0};
bool inside(int y,int x,int h,int w){
	if(y<h && y>=0 && x<w && x>=0) return true;
	return false;
}





int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s,t;cin >> s >> t;
	int n = s.size(), m = t.size();
	vector<pii> cnts(n + 1), cntt(m + 1);
	rep(i,n){
		if(s.at(i) == 'A') cnts.at(i + 1).first++;
		else cnts.at(i + 1).second++;
		cnts.at(i + 1).first += cnts.at(i).first;
		cnts.at(i + 1).second += cnts.at(i).second;
	}
	rep(i,m){
		if(t.at(i) == 'A') cntt.at(i + 1).first++;
		else cntt.at(i + 1).second++;
		cntt.at(i + 1).first += cntt.at(i).first;
		cntt.at(i + 1).second += cntt.at(i).second;
	}
	int q;cin >> q;
	while(q--){
		int a,b,c,d;cin >> a >> b >> c >> d;
		int k1 = cnts.at(b).first - cnts.at(a - 1).first, k2 = cnts.at(b).second - cnts.at(a - 1).second;
		int k3 = cntt.at(d).first - cntt.at(c - 1).first, k4 = cntt.at(d).second - cntt.at(c - 1).second;
		if((k1 % 3 - k2 % 3 + 3) % 3 == (k3 % 3 - k4 % 3 + 3) % 3) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
