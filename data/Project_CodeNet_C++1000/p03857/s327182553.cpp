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
	int n,t,l;cin >> n >> t >> l;
	vector<vector<int>> g1(n,vector<int>()), g2(n,vector<int>());
	rep(i,t){
		int p,q;cin >> p >> q;
		p--;q--;
		g1[p].pb(q);
		g1[q].pb(p);
	}
	rep(i,l){
		int r,s;cin >> r >> s;
		r--;s--;
		g2[r].pb(s);
		g2[s].pb(r);
	}
	vector<pii> a(n);
	map<pii,int> m;
	queue<int> q;
	int k = 1;
	rep(i,n){
		if(a.at(i).first == 0){
			a.at(i).first = k;
			q.push(i);
			while(!q.empty()){
				int cur = q.front();q.pop();
				rep(j,g1.at(cur).size()){
					int next = g1.at(cur).at(j);
					if(a.at(next).first != 0) continue;
					a.at(next).first = k;
					q.push(next);
				}
			}
			k++;
		}
	}
	k = 1;
	rep(i,n){
		if(a.at(i).second == 0){
			a.at(i).second = k;
			q.push(i);
			while(!q.empty()){
				int cur = q.front();q.pop();
				rep(j,g2.at(cur).size()){
					int next = g2.at(cur).at(j);
					if(a.at(next).second != 0) continue;
					a.at(next).second = k;
					q.push(next);
				}
			}
			k++;
		}
	}
	vector<int> ans(n);
	rep(i,n) m[a.at(i)]++;
	rep(i,n) ans.at(i) = m[a.at(i)];
	rep(i,n){
		if(i == n - 1) cout << ans.at(i) << endl;
		else cout << ans.at(i) << " ";
	}
}
