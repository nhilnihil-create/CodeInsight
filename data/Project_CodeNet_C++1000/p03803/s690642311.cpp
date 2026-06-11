#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for ( int i = 0; i < (int)(n); i++ )

int main( void )
{
    int a,b;
    cin >> a >> b;
    
    if ( a == 1 )
        a += 13;
    if ( b == 1 )
        b += 13;
    
    if ( a > b )
        cout << "Alice" << endl;
    else if ( b > a )
        cout << "Bob" << endl;
    else if ( a == b )
        cout << "Draw" << endl;
    
}
