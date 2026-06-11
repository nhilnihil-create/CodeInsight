#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for ( int i = 0; i < (int)(n); i++ )

int main( void )
{
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    
    ll ans = max(a*b,c*d);
    cout << ans << endl;
}
