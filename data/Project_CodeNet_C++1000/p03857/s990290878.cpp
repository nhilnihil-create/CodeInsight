#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

const int MAXN = 200010;

int n, k, l;

int ind[MAXN];
int ans[MAXN];
int freq[MAXN];

bool marc[MAXN][2];

vector< int > component;

vector< int > adj[MAXN][2];

void DFS(int cur, int t, int root = 0)
{
	marc[cur][t] = true;
	
	if( t == 0 ) ind[ cur ] = root;
	else component.push_back( cur );

	for(int i = 0 ; i < adj[cur][t].size() ; i++)
	{
		int viz = adj[cur][t][i];

		if( !marc[viz][t] ) DFS( viz , t , root );
	}
}

int main()
{
	scanf("%d %d %d",&n,&k,&l);

	for(int i = 1 ; i <= k ; i++)
	{
		int U, V;
		scanf("%d %d",&U,&V);

		adj[ U ][0].push_back( V );
		adj[ V ][0].push_back( U );
	}

	for(int i = 1 ; i <= l ; i++)
	{
		int U, V;
		scanf("%d %d",&U,&V);

		adj[ U ][1].push_back( V );
		adj[ V ][1].push_back( U );
	}

	for(int i = 1 ; i <= n ; i++)
		if( !marc[i][0] ) DFS( i , 0 , i );

	for(int i = 1 ; i <= n ; i++)
	{
		if( marc[i][1] ) continue;

		DFS( i , 1 );

		for(int j = 0 ; j < component.size() ; j++)
		{
			int cur = component[j];
			freq[ ind[cur] ]++;
		}

		for(int j = 0 ; j < component.size() ; j++)
		{
			int cur = component[j];
			ans[cur] = freq[ ind[cur] ];
		}

		for(int j = 0 ; j < component.size() ; j++)
		{
			int cur = component[j];
			freq[ ind[cur] ]--;
		}

		component.clear();
	}

	for(int i = 1 ; i <= n ; i++)
		printf("%d ",ans[i]);
}