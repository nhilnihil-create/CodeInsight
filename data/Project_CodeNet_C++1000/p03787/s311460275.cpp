#include <bits/stdc++.h>
using namespace std;

const int DIM = 1e5 + 5;

int lev[DIM];

vector<int> edg[DIM];

void dfs( int x, int f, bool &ok ) {
    lev[x] = lev[f] + 1;
    
    for( int y : edg[x] ) {
        if( y == f )
            continue;
        
        if( lev[y] == 0 )
            dfs( y, x, ok );
        else
        if( ( lev[x] - lev[y] ) % 2 == 0 )
            ok = false;
    }
    
    return;
}

int main( void ) {
    
    int n, m;
    cin >> n >> m;
    
    for( int i = 1; i <= m; i ++ ) {
        int x, y;
        cin >> x >> y;
        
        edg[x].push_back( y );
        edg[y].push_back( x );
    }
    
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for( int i = 1; i <= n; i ++ ) {
        if( lev[i] != 0 )
            continue;
        
        if( edg[i].size() == 0 )
            cnt1 ++;
        else {
            bool ok = true;
            dfs( i, 0, ok );
            
            if( ok == true )
                cnt2 ++;
            else
                cnt3 ++;
        }
    }
    
    cout << 1LL * cnt1 * cnt1 + 2LL * cnt1 * (n - cnt1) +
            1LL * cnt3 * cnt3 + 2LL * cnt2 * cnt3 + 2LL * cnt2 * cnt2;
    
    return 0;
}