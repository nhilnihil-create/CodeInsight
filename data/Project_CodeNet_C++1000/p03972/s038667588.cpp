//
//  main.cpp
//

#include <algorithm>
#include <array>
#include <assert.h>
#include <iomanip>
#include <iostream>
#include <limits>
#include <math.h>
#include <memory>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = int64_t;
using ull = uint64_t;

template<typename T>
vector<T> make_vec_nd(T init, size_t size) {
    return vector<T>(size, init);
}
template<typename T, typename... Args>
auto make_vec_nd(T init, size_t size, Args... rest) {
    auto inner = make_vec_nd(init, rest...);
    return vector<decltype(inner)>(size, inner);
}

#define rep(i,a,b) for(ll i=(a);i<(b);i++)
#define rrep(i,a,b) for(ll i=(a)-1;i>=(b);i--)

int main() {
    struct CostInfo {
        bool is_hori;
        ll cost;
    };
    ll W, H;
    cin >> W >> H;
    vector<CostInfo> costs;
    rep(i,0,W) {
        ll c;
        cin >> c;
        costs.push_back({true, c});
    }
    rep(i,0,H) {
        ll c;
        cin >> c;
        costs.push_back({false, c});
    }
    sort(costs.begin(), costs.end(), [](CostInfo lhs, CostInfo rhs){
        return lhs.cost < rhs.cost;
    });
    ll hori_cnt = 0;
    ll vert_cnt = 0;
    ll ans = 0;
    for (CostInfo ci : costs) {
        if (ci.is_hori) {
            ans += ci.cost * ((H+1) - vert_cnt);
            hori_cnt++;
        } else {
            ans += ci.cost * ((W+1) - hori_cnt);
            vert_cnt++;
        }
    }
    cout << ans << endl;
}

