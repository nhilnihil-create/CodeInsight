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
vector<T> make_vec_nd(T init, ll size) {
    return vector<T>(size, init);
}
template<typename T, typename... Args>
auto make_vec_nd(T init, ll size, Args... rest) {
    auto inner = make_vec_nd(init, rest...);
    return vector<decltype(inner)>(size, inner);
}

#define rep(i,a,b) for(ll i=(a);i<(b);i++)
#define rrep(i,a,b) for(ll i=(a)-1;i>=(b);i--)

int main() {
    ll N;
    cin >> N;
    string s;
    cin >> s;
    rep(i,0,4) {
        vector<char> ans(N+3);
        if (i == 0) {
            ans[0] = 'S';
            ans[1] = 'S';
        } else if (i == 1) {
            ans[0] = 'S';
            ans[1] = 'W';
        } else if (i == 2) {
            ans[0] = 'W';
            ans[1] = 'S';
        } else {
            ans[0] = 'W';
            ans[1] = 'W';
        }
        rep(i,2,N+2) {
            if ((ans[i-1] == 'S' && s[(i-1)%N] == 'o') || (ans[i-1] == 'W' && s[(i-1)%N] == 'x')) {
                ans[i] = ans[i-2];
            } else {
                if (ans[i-2] == 'W') {
                    ans[i] = 'S';
                } else {
                    ans[i] = 'W';
                }
            }
        }
        if (ans[0] == ans[N] && ans[1] == ans[N+1]) {
            rep(i,0,N) {
                cout << ans[i];
            }
            cout << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}

