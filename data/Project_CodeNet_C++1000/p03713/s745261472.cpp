#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using ll = long long;

int main(){
    ll h, w;
    std::cin >> h >> w;
    if(h % 3 == 0 || w % 3 == 0){
        std::cout << 0 << std::endl;
        return 0;
    }

    ll r;

    // 横で最初に分割
    ll minCost = 1000000000000;
    r = w % 2;
    for(ll i = 1; i <= h / 2; i++){
        ll s_tmp = i * w;
        ll s_other1 = (h - i) * ((w + r) / 2);
        ll s_other2 = (h - i) * ((w - r) / 2);
        ll tmpCost = std::max({s_tmp, s_other1, s_other2}) - std::min({s_tmp, s_other1, s_other2});
        minCost = std::min(tmpCost, minCost);
    }

    // 縦で最初に分割
    r = h % 2;
    for(ll j = 1; j <= w / 2; j++){
        ll s_tmp = j * h;
        ll s_other1 = (w - j) * ((h + r) / 2);
        ll s_other2 = (w - j) * ((h - r) / 2);
        ll tmpCost = std::max({s_tmp, s_other1, s_other2}) - std::min({s_tmp, s_other1, s_other2});
        minCost = std::min(tmpCost, minCost);
    }

    std::cout << std::min({minCost, h, w}) << std::endl;
    return 0;
}
