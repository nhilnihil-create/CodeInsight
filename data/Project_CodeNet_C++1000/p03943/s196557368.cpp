#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for ( int i = 0; i < (int)(n); i++ )

bool func( int x, int y, int z )
{
    if ( x + y == z )
    {
        cout << "Yes" << endl;
        return true;
    }
    else
        return false;
}

int main( void )
{
    int a,b,c;
    cin >> a >> b >> c;
    
    if ( a + b == c || a + c == b || b + c ==a )
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
