#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for ( int i = 0; i < (int)(n); i++ )

int main( void )
{
    ll x,t;
    cin >> x >> t;
    
    if ( x - t > 0 )
        cout << x - t << endl;
    else
        cout << 0 << endl;
}
