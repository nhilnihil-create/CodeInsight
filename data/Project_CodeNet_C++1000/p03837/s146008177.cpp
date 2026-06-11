#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;

const int MAXN = 110;
const int INF = 1000000010;

int n, m;

int dp[MAXN][MAXN];

vector< pair<pii,int> > edges;

int main()
{
	scanf("%d %d",&n,&m);

	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= n ; j++)
			dp[i][j] = INF;

	for(int i = 1 ; i <= n ; i++)
		dp[i][i] = 0;

	for(int i = 1 ; i <= m ; i++)
	{
		int U, V, W;
		scanf("%d %d %d",&U,&V,&W);

		dp[U][V] = dp[V][U] = W;

		edges.push_back( { {U , V} , W } ); 
	}

	for(int k = 1 ; k <= n ; k++)
		for(int U = 1 ; U <= n ; U++)
			for(int V = 1 ; V <= n ; V++)
				dp[U][V] = min( dp[U][V] , dp[U][k] + dp[k][V] );

	int ans = 0;

	for(int i = 0 ; i < m ; i++)
	{
		int U = edges[i].first.first;
		int V = edges[i].first.second;
		int W = edges[i].second;

		bool noShortestPath = false;

		for(int s = 1 ; s <= n ; s++)
		{
			for(int t = 1 ; t <= n ; t++)
			{
				int dist = dp[s][U] + W + dp[V][t];

				noShortestPath = noShortestPath || ( dist == dp[s][t] );
			}
		}

		if( !noShortestPath ) ans++;
	}

	printf("%d\n",ans);
}