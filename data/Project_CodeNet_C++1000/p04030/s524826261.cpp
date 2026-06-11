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
#include <queue>
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define fast_io(); std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main(){
    std::string s;
    std::cin >> s;
    std::string ss="";
    rep(i,s.size()){
        if(s[i]=='B'&&ss.size()!=0){
            ss.pop_back();
        }else if(s[i]=='B'){
            continue;
        }else{
            ss.push_back(s[i]);
        }
    }
    std::cout << ss << "\n";
    return 0;
}