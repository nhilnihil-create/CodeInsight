#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXN = 100010;
 
int n, m;
 
bool marc[MAXN];
 
vector< int > path[2];
vector< int > adj[MAXN];
 
void DFS(int cur, int t)
{
	marc[ cur ] = true;
	path[ t ].push_back( cur );
 
	for(int i = 0 ; i < adj[cur].size() ; i++)
	{
		int viz = adj[cur][i];
 
		if( !marc[viz] ) return void( DFS( viz , t ) );
	}
}
 
int main()
{
	scanf("%d %d",&n,&m);
 
	for(int i = 1 ; i <= m ; i++)
	{
		int U, V;
		scanf("%d %d",&U,&V);
 
		adj[ U ].push_back( V );
		adj[ V ].push_back( U );
	}
 
	DFS( 1 , 0 );
	DFS( 1 , 1 );
 
	reverse( path[1].begin() , path[1].end() );
	path[1].pop_back();
  
	printf("%d\n",path[0].size() + path[1].size());
 
	for(int i = 0 ; i < path[1].size() ; i++)
		printf("%d ",path[1][i]);
 
	for(int i = 0 ; i < path[0].size() ; i++)
		printf("%d ",path[0][i]);
}