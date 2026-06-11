#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
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
	int n,t;cin >> n >> t;
	vector<int> a(n);
	rep(i,n) cin >> a.at(i);
	int r = 1, k = 0;
	map<int,int> m;
	rep(i,n){
		while(r < n && a.at(i) < a.at(r)){
			k = max(k, a.at(r) - a.at(i));
			r++;
		}
		if(k) m[k]++;
		i = r - 1;
		r++;
		k = 0;
	}
	int ans = 0, ma = 0;
	for(auto i : m){
		if(i.first > ma){
			ma = i.first;
			ans = i.second;
		}
	}
	cout << ans << endl;
}
