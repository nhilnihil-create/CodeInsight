#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <numeric>
#include <cstdint>
#include <iomanip>
using ll = long long;

ll gumoji(std::string s){
    if(s.size()%2) return -1;
    if(s.substr(0,s.size()/2)==s.substr(s.size()/2)) return (ll)s.size();
    return -1;
}

int main(){
    std::string s; std::cin >> s;

    ll ans=0;
    for(;s.size()>0;){
        s.pop_back();
        ll b = gumoji(s);
        ans = std::max(ans, b);
    }
    std::cout << ans;
    return 0;
}
