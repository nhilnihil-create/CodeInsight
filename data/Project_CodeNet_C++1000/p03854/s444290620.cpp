#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <numeric>
#include <cstdint>
#include <iomanip>
#include <set>
#include <map>
#include <unordered_map>
#include <cassert>
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main(){
    std::string s;
    std::cin >> s;

    std::reverse(s.begin(),s.end());
    while(s.size()>0){
        if(s.substr(0,7)=="remaerd"){
            s.erase(0,7);
            continue;
        }
        if(s.substr(0,5)=="maerd"){
            s.erase(0,5);
            continue;
        }
        if(s.substr(0,5)=="esare"){
            s.erase(0,5);
            continue;
        }
        if(s.substr(0,6)=="resare"){
            s.erase(0,6);
            continue;
        }
        break;
    }

    if(s.size()==0) std::cout << "YES" << "\n";
    else std::cout << "NO" << "\n";
    return 0;
}