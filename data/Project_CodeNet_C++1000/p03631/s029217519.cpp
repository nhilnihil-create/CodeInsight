#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for ( int i = 0; i < (int)(n); i++ )

int main( void )
{
    int n;
    cin >> n;
    
    if ( n / 100 - n % 10 )
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
}
