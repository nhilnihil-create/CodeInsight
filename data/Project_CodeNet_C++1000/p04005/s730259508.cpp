#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main(){
    ll a,b,c;
    std::cin >> a >> b >> c;

    ll ans = a*b*c - 2*(a/2)*b*c;
    ans = std::min(ans, a*b*c - 2*a*(b/2)*c);
    ans = std::min(ans, a*b*c - 2*a*b*(c/2));

    std::cout << ans << "\n";
    return 0;
}
