#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 1;
vector<int> edges[MAX_N];
bool check[MAX_N];

int dfs( int u ) {
    check[u] = 1;
    int ans = 0;
    for ( int v : edges[u] )
        if ( !check[v] ) {
            ans ^= 1 + dfs( v );
        }
    return ans;
}

int main() {
    int n;
    cin >> n;

    for ( int i = 0; i < n - 1; i++ ) {
        int x, y;
        cin >> x >> y;
        edges[x].push_back( y );
        edges[y].push_back( x );
    }

//    cout << dfs(1);
    cout << ( dfs( 1 ) ? "Alice" : "Bob" );

    return 0;
}
