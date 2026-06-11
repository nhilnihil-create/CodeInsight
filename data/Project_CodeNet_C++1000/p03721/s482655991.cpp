#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
const std::string yes = "Yes";
const std::string no  = "No";

int main(){
    fast_io();

    int n; ll k; std::cin >> n >> k;
    std::vector<std::pair<ll,ll>> ab(n);
    rep(i,n) std::cin >> ab[i].first >> ab[i].second;

    std::sort(ab.begin(),ab.end());

    for(auto abi:ab){
        k -= abi.second;
        if(k<1){
            std::cout << abi.first << "\n";
            return 0;
        }
    }
}
