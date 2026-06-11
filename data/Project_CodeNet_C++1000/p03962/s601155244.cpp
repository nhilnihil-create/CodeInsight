#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)

int main( void )
{
    int a,b,c;
    cin >> a >> b >> c;
    
    int ans = 1;
    
    if ( a != b )
        ans++;
    if ( a != c && b != c)
        ans++;
    
    cout << ans << endl;
}
