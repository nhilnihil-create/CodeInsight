#include <bits/stdc++.h>
using namespace std;
#define dhoom ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);  
typedef long long ll;
typedef long double ld;
const ll inf = 1e18;
const int nax = 2e6 + 7;
const ll mod = 1e9 + 7;
//ll tree[4 * nax];
//9uS-22RSwk7gQqh
vector< pair< int , int > > g;
int wt[1001];
int ans[1001];
int dis[101][101];
int main()
{
	int n , m;
	cin >> n >> m;
	for(int i = 1 ; i <= 100 ; i++){
		for(int j = 1 ; j <= 100 ; j++){
			if(i == j)
				dis[i][j] = 0;
			else 
				dis[i][j] = 9999999;
		}
	}
	for(int i = 0 ; i < m ; i++){
		int u , v , w;
		cin >> u >> v >> w;
		g.push_back({u,v});
		wt[i] = w;
		dis[u][v] = dis[v][u] = w;
	}
	for(int k = 1 ; k <=  n ; k++){
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= n ; j++){
					dis[i][j] = min(dis[i][j] , dis[i][k] + dis[k][j]);
			}
		}
	}
	for(int i = 0 ; i < m ; i++){
		int u = g[i].first;
		int v = g[i].second;
		for(int j = 1 ; j <= n ; j++){
			for(int k = j + 1 ;k <= n ; k++){
				if(dis[j][u] + dis[v][k] + wt[i] == dis[j][k] ||dis[j][v] + dis[u][k] + wt[i] == dis[j][k])
					ans[i] = 1;
			}
		}
	}
	int cnt = 0;
	for(int i = 0 ; i < m ; i++)
		if(!ans[i])
			cnt++;
	cout << cnt << endl;
	return 0;
}

