#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for ( int i = 0; i < (int)(n); i++ )

int main( void )
{
    int a,b;
    cin >> a >> b;
    
    int sum = a + b;
    if ( sum > 9 )
        cout << "error" << endl;
    else
        cout << sum << endl;
}
