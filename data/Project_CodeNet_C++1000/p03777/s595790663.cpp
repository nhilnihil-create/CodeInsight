#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for ( int i = 0; i < (int)(n); i++ )

int main( void )
{
    char a,b;
    cin >> a >> b;
    
    int ans = 1;
    if ( a == 'D' )
        ans *= -1;
    if ( b == 'D' )
        ans *= -1;
    
    if ( ans > 0 )
        cout << 'H' << endl;
    else
        cout << 'D' << endl;
}
