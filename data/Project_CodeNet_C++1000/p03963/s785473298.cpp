#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main(){
    ll n,k;
    std::cin >> n >> k;

    ll ans = k*pow(k-1,n-1);
    std::cout << ans << "\n";
    return 0;
}
