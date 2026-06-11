#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for ( int i = 0; i < (int)(n); i++ )

int main( void )
{
    int a,b,c;
    cin >> a >> b >> c;
    
    if ( max(a,c) - b == b - min(a,c) )
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
