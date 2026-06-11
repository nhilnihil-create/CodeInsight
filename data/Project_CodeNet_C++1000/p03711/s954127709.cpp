#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for ( int i = 0; i < (int)(n); i++ )

int groupting( int a )
{
    if ( a < 8 && a % 2 == 1 || a > 7 && a % 2 == 0 )
        return 1;
    else if ( a == 2 )
        return 3;
    else
        return 2;
}

int main( void )
{
    int x,y;
    cin >> x >> y;
    
    int groupx = groupting(x),groupy = groupting(y);
    if ( groupx == groupy )
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
