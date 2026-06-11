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

struct Node {
    ll parent;
    vector<ll> child;
};

vector<Node> tree;

ll dfs(ll cur) {
    vector<ll> depths;
    for (ll ch : tree[cur].child) {
        ll depth = dfs(ch);
        depths.push_back(depth);
    }
    sort(depths.rbegin(), depths.rend());
    ll mn = 0;
    for (ll i = 0; i < depths.size(); i++) {
        mn = max(mn, i + 1 + depths[i]);
    }
//    cout << "cur: " << cur << ", mn: " << mn << endl;
    return mn;
}

int main() {
    ll N;
    cin >> N;
    tree = vector<Node>(N);
    tree[0].parent = -1;
    for (ll i = 1; i < N; i++) {
        ll ai;
        cin >> ai;
        ai--;
        tree[i].parent = ai;
        tree[ai].child.push_back(i);
    }
    cout << dfs(0) << endl;
}

