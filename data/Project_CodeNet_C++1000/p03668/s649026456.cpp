#include <bits/stdc++.h>
  
using namespace std;
  
#define rep(i,n) REP(i,0,n)
#define REP(i,s,e) for(int i=(s); i<(int)(e); i++)
#define pb push_back
#define all(r) r.begin(),r.end()
#define rall(r) r.rbegin(),r.rend()
#define fi first
#define se second
  
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
const int INF = 1e9;
const ll MOD = 1e9 + 7;
double EPS = 1e-8;

vector<int> es[100010];

int dfs(int now, int par) {
	int ret = 0LL;
	for(auto& to : es[now]) {
		if(to == par) continue;
		ret ^= (dfs(to, now) + 1);
	}
	return ret;
}


int main(){
	int n;
	cin >> n;
	rep(i, n-1) {
		int x, y;
		cin >> x >> y;
		x--;y--;
		es[x].pb(y);
		es[y].pb(x);
	}
	cout << (dfs(0, -1) ? "Alice": "Bob") << endl;
	return 0;
}