#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <utility>

using namespace std;

constexpr int ms = 100100;

vector<int> g[ms];
deque<bool> explored(ms, false);
int node_xor[ms];

void explore( int root ) {
    explored[ root ] = true;
    int countKid = 0;
    for(const int& nei : g[root] ) {
        if( explored[nei] == false ) {
            countKid++;
            explore(nei);
            node_xor[root] ^= node_xor[nei];
        }
    }
    if( root != 0 ) node_xor[root]++;
}


int main()
{
    int n;
    ios::sync_with_stdio( false ); cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back( b );
        g[b].push_back( a );
    }

    explore(0);
    
    cout << ( node_xor[0] == 0 ? "Bob" : "Alice") << endl;
    return 0;
}
