#include <bits/stdc++.h>
using namespace std;

const int DIM = 1e5 + 5;

int arr[DIM];

int main( void ) {
    
    int n, m;
    cin >> n >> m;
    
    int cnt = 0;
    for( int i = 1; i <= m; i ++ ) {
        cin >> arr[i];
        cnt += arr[i] % 2;
    }
    
    if( cnt > 2 )
        cout << "Impossible\n";
    else
    if( n == 1 )
        cout << "1\n1\n1\n";
    else
    if( m == 1 )
        cout << arr[1] << "\n" << "2\n" << arr[1] - 1 << " 1\n";
    else {
        int p = 0;
        for( int i = 1; i <= m; i ++ )
            if( arr[i] % 2 == 1 )
                swap( arr[i], arr[++ p] );
        swap( arr[2], arr[m] );
        
        for( int i = 1; i <= m; i ++ )
            cout << arr[i] << " ";
        cout << "\n" << m - ( arr[1] == 1 ) << "\n";
        
        if( arr[1] != 1 )
            cout << arr[1] - 1 << " ";
        
        for( int i = 2; i <= m - 1; i ++ )
            cout << arr[i] << " ";
        cout << arr[m] + 1 << "\n";
    }
    
    return 0;
}