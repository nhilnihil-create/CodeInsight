#include <iostream>
typedef long long ll;
#define REP(i, n) for (int(i) = 0; (i) < (int)(n); i++)

int main()
{
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int n ;
    std::cin >> n ;
    ll ans = 0 ;
    ll a, b ;
    REP(i,n){
        std::cin >> a ;
        if(i==0 || a==0){
            ans += a/2 ;
            b = a%2 ;
            continue ;
        }
        ans += b+ (a-b)/2 ;
        a -= b ;
        b = a%2 ;
    }
    std::cout << ans << std::endl ;
    return 0;
}
