#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for ( int i = 0; i < (int)(n); i++ )

int main( void )
{
    string a,b,c;
    cin >> a >> b >> c;
    
    int la = a.length(),lb = b.length();
    if ( a[la-1] == b[0] && b[lb-1] == c[0] )
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
