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
	int n;cin >> n;
	vector<int> a(n);
	rep(i,n) cin >> a.at(i);
	vector<ll> ans(n);
	priority_queue<pair<int,pii>> pq;
	rep(i,n){
		pq.push(mp(a.at(i),mp(1,i)));
	}
	while(pq.size() > 1){
		pair<int,pii> b = pq.top();pq.pop();
		pair<int,pii> c = pq.top();pq.pop();
		if(b.second.second < c.second.second){
			ans.at(b.second.second) += (ll)(b.first - c.first) * b.second.first;
			b.second.first += c.second.first;
			b.first = c.first;
			pq.push(b);
		}
		else{
			ans.at(b.second.second) += (ll)(b.first - c.first) * b.second.first;
			c.second.first += b.second.first;
			pq.push(c);
		}
	}
	ans.at(0) += (ll)pq.top().first * pq.top().second.first;
	rep(i,n) cout << ans.at(i) << endl;
}
