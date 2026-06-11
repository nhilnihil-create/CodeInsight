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
#define printP(x) "(" << (x).first << ", " << (x).second << ")"
#define mod 1000000007
using namespace std;
typedef pair<llint, llint> P;

llint n, m;
vector<llint> G[100005];
llint color[100005];

bool dfs(int v, int p, int c)
{
	color[v] = c;
	bool ret = true;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		if(color[G[v][i]] == -c) continue;
		if(color[G[v][i]] == c){
			ret = false;
			continue;
		}
		ret &= dfs(G[v][i], v, -c);
	}
	return ret;
}

int main(void)
{
	cin >> n >> m;
	llint u, v;
	for(int i = 1; i <= m; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	llint cnt = 0, bcnt = 0, icnt = 0;
	for(int i = 1; i <= n; i++){
		if(color[i]) continue;
		if(G[i].size() == 0) icnt++;
		else if(dfs(i, -1, 1)) bcnt++;
		else cnt++;
	}
	llint ans = icnt*n*2 - icnt*icnt;
	ans += 2*bcnt*cnt + cnt*cnt;
	ans += 2*bcnt*bcnt;
	cout << ans << endl;
	
	return 0;
}
