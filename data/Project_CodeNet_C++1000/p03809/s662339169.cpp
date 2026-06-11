#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define mod 998244353
using namespace std;
typedef pair<llint, llint> P;
typedef pair<P, llint> E;

llint n;
llint a[100005];
vector<llint> G[100005];

llint dfs(int v, int p)
{
	if(G[v].size() == 1) return a[v];
	
	llint ret = 0, mx = 0;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		llint res = dfs(G[v][i], v);
		if(res < 0) return -1;
		ret += res;
		mx = max(mx, res);
	}
	if(a[v] > ret) return -1;
	
	llint nump = ret-a[v], maxp = min(ret-mx, ret/2);
	if(nump > maxp) return -1;
	return ret - 2*nump;
}

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	llint u, v;
	for(int i = 1; i <= n-1; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if(n == 2){
		if(a[1] == a[2]) cout << "YES" << endl;
		else cout << "NO" << endl;
		return 0;
	}
	
	llint root;
	for(int i = 1; i <= n; i++){
		if(G[i].size() > 1){
			root = i;
			break;
		}
	}
	if(dfs(root, -1)) cout << "NO" << endl;
	else cout << "YES" << endl;
	
	return 0;
}
