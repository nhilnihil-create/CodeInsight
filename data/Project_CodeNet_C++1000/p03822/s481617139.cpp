#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <typeinfo>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <bitset>
#include <stack>


using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e16;
const ll MOD = 1e9 + 7;

#define REP(i, n) for(ll i = 0; i < n; i++)






vector<vector<int>> g;

int dfs(int now, int par){
    vector<int> depth;
    for(auto &child : g[now]){
        if(child == par) continue;
        depth.push_back(dfs(child, now));
    }
    sort(depth.begin(), depth.end());
    int mx = 0;
    for(int i = 0; i < depth.size(); i++){
        mx = max(mx, depth[i] + ((int)depth.size() - i));
    }
    return mx;
}

int main() {
    int n;
    cin >> n;
    g.resize(n);
    for(int i = 1; i < n; i++){
        int a;
        cin >> a;
        a--;
        g[i].push_back(a);
        g[a].push_back(i);
    }
    cout << dfs(0, -1) << endl;
}
