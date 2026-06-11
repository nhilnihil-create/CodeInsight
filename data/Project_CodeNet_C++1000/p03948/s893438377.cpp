#include <bits/stdc++.h>
using namespace std;
 
const int DIM = 1e5 + 5;
 
int mxm[DIM], arr[DIM];
 
int main( void ) {
    
    int n, t;
    cin >> n >> t;
    
    int ans = 0, cnt = 0;
    for( int i = 1; i <= n; i ++ )
        cin >> arr[i];
    
    for( int i = n; i >= 1; i -- ) {
        mxm[i] = max( mxm[i + 1], arr[i] );
        arr[i] = mxm[i] - arr[i];
        
        if( ans < arr[i] ) {
            ans = arr[i];
            cnt = 1;
        } else
        if( ans == arr[i] )
            cnt ++;
    }
    
    cout << cnt << endl;
    return 0;
}