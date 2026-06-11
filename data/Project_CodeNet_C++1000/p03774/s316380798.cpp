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
    ll N, M; std::cin >> N >> M;
    std::vector<ll> a, b, c, d;
    for(int i=0; i<N; ++i){
        ll buf; std::cin >> buf; a.push_back(buf);
        std::cin >> buf; b.push_back(buf);
    }
    for(int i=0; i<M; ++i){
        ll buf; std::cin >> buf; c.push_back(buf);
        std::cin >> buf; d.push_back(buf);
    }

    std::vector<ll> ret(N,0);
    for(int i=0; i<N; ++i){
        ll buf=1145141919;
        for(int j=0; j<M; ++j){
            if(buf>abs(a[i]-c[j])+abs(b[i]-d[j])){
                buf = abs(a[i]-c[j])+abs(b[i]-d[j]);
                ret[i] = j+1;
            }
        }
    }

    for(int i=0; i<N; ++i){
        std::cout << ret[i] << '\n';
    }
    return 0;
}
