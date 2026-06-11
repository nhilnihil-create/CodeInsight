
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <numeric>
#include <cstdint>
#include <iomanip>
using ll = long long;

int main(){
    ll n; std::cin>>n;
    std::vector<ll> a;
    for(int i=0; i<n; ++i){
        ll b; std::cin>>b; a.push_back(b);
    }

    std::sort(a.begin(), a.end());

    std::vector<ll> d(a.back()+3, 0);
    for(int i=0; i<a.size(); ++i){
        ++d[a[i]];
    }

    ll cnt=0;
    for(int i=0; i<a.back()+1; ++i){
        ll buf = d[i] + d[i+1] + d[i+2];
        cnt = std::max(cnt, buf);
    }
    std::cout << cnt;
    return 0;
}
