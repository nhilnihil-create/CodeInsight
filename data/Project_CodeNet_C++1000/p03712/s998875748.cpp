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
    fast_io();

    int h,w; std::cin >> h >> w;
    std::string s(w+2,'#');
    std::vector<std::string> stage(h+2,s);

    for(int i=1; i<h+1; i++){
        for(int j=1; j<w+1; j++){
            char a; std::cin >> a;
            stage[i][j] = a;
        }
    }

    for(int i=0; i<stage.size(); i++){
        std::cout << stage[i] << "\n";
    }

    return 0;
}