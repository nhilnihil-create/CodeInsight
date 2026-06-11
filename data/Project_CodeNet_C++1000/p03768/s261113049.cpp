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

llint n, m, Q;
vector<llint> G[100005];
llint dist[100005], color[100005];
vector<P> vec[15][100005];
P dp[15][100005];

int main(void)
{
	cin >> n >> m;
	llint u, v;
	for(int i = 1; i <= m; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	cin >> Q;
	llint d, c;
	for(int i = 1; i <= Q; i++){
		cin >> v >> d >> c;
		vec[d][v].push_back(P(i, c));
	}
	
	for(int i = 10; i >= 0; i--){
		for(int j = 1; j <= n; j++){
			for(int k = 0; k < vec[i][j].size(); k++){
				dp[i][j] = max(dp[i][j], vec[i][j][k]);
			}
			if(i > 0){
				dp[i-1][j] = max(dp[i-1][j], dp[i][j]);
				for(int k = 0; k < G[j].size(); k++){
					llint u = G[j][k];
					dp[i-1][u] = max(dp[i-1][u], dp[i][j]);
				}
			}
		}
	}
	for(int i = 1; i <= n; i++) cout << dp[0][i].second << endl;
	
	return 0;
}
