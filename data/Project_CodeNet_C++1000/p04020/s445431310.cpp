#include <iostream>

using namespace std;
typedef long long ll;

#define REP(i, n) for (int(i) = 0; (i) < (int)(n); i++)

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n ;
    cin >> n ;
    ll ans = 0 ;
    ll a, b ;
    REP(i,n){
        cin >> a ;
        if(i==0){
            ans += a/2 ;
            b = a%2 ;
            continue ;
        }
        if(a==0){
            b = 0 ;
            continue ;
        }
        ans += b ;
        a -= b ;
        ans += a/2 ;
        b = a%2 ;
    }
    cout << ans << endl ;
    return 0;
}
