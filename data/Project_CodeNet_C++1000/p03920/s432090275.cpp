#include <bits/stdc++.h>
using namespace std;

vector<int> arr;

int main( void ) {
    
    int n;
    cin >> n;
    
    for( int i = 1; i <= n; n -= i ++ )
        arr.push_back( i );

    reverse( arr.begin(), arr.end() );
    for( int i = 0; i < n; i ++ )
        arr[i] ++;
    
    reverse( arr.begin(), arr.end() );
    for( int i = 0; i < arr.size(); i ++ )
        cout << arr[i] << '\n';
    
    return 0;
}