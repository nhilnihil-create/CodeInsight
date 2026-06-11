#include <iostream>
#include <vector>

#define MAX_N 2000

using namespace std;

typedef pair<int, int> P;

int dist[MAX_N][MAX_N]; // dist[u][v] = 頂点 u と頂点 v の距離
int num[MAX_N]; // num[v] = 頂点 v からの距離が K/2 以上の頂点の個数

int N, K;
vector<int> G[MAX_N];
P edges[MAX_N];

void distDFS( int root, int v, int d, int par )
{
    dist[root][v] = dist[v][root] = d;

    for ( auto u : G[v] )
    {
        if ( u == par ) continue;

        distDFS( root, u, d + 1, v );
    }
}

int main( int argc, char **argv )
{
    cin >> N >> K;

    for ( int i = 0; i < N - 1; i++ )
    {
        int A, B;
        cin >> A >> B;

        G[A - 1].push_back( B - 1 );
        G[B - 1].push_back( A - 1 );

        edges[i] = P( A - 1, B - 1 );
    }

    for ( int i = 0; i < N; i++ ) distDFS( i, i, 0, -1 );

    int ans = ( 1 << 30 );
    if ( K % 2 == 0 )
    {

        for ( int u = 0; u < N; u++ )
        {
            int num = 0;
            for ( int v = 0; v < N; v++ )
                if ( dist[u][v] > K / 2 ) num++;
            ans = min( num, ans );
        }
    }
    else
    {
        for ( int i = 0; i < N - 1; i++ )
        {
            int u1 = edges[i].first;
            int u2 = edges[i].second;

            int num = 0;
            for ( int v = 0; v < N; v++ )
                if ( min( dist[u1][v], dist[u2][v] ) > K / 2 ) num++;
            ans = min( num, ans );
        }
    }

    cout << ans << endl;

    return 0;
}
