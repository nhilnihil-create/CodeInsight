//In the name of 'ALLAH'
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll a , b , c ;
    cin >> a >> b >> c ;
    ll ans = ( b/c  - a/c);

    if( a%c ==0)
    {
        ans ++;
    }
    cout << ans << endl;
    return 0;
}
