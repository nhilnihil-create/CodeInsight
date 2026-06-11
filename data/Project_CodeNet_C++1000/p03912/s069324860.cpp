#include <bits/stdc++.h>
using namespace std;

const int DIM = 1e5 + 5;

int cnt1[DIM], frq[DIM], cnt2[DIM];

int main( void ) {
    
    int n, m;
    cin >> n >> m;
    
    for( int i = 1; i <= n; i ++ ) {
        int x;
        cin >> x;
        
        cnt1[x % m] ++;
        
        frq[x] ++;
        if( frq[x] % 2 == 0 )
            cnt2[x % m] ++;
    }
    
    int ans = cnt1[0] / 2;
    cnt1[0] = 0;
   
    if( m % 2 == 0 ) {
        ans += cnt1[m / 2] / 2;
        cnt1[m / 2] = 0;
    }
    
    for( int i = 1; i <= m / 2; i ++ ) {
        int aux = min( cnt1[i], cnt1[m - i] );
        
        ans += aux;
        cnt1[i] -= aux;
        cnt1[m - i] -= aux;
    }
    
    for( int i = 1; i < m; i ++ )
        ans += min( cnt1[i] / 2, cnt2[i] );
    
    cout << ans << endl;
    return 0;
}
