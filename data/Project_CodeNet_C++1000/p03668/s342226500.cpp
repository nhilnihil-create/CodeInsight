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
#include <assert.h>
#include <unordered_set>
#include <random>



using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;

#define REP(i, n) for(ll i = 0; i < n; i++)










vector<vector<ll>> g;
ll xorsum = 0;
 
ll dfs(ll now, ll par){
    ll res = 0;
    for(auto &child : g[now]){
        if(child == par) continue;
        res ^= dfs(child, now) + 1;
    }
    return res;
}
 
 
 
int main(){
    ll n;
    cin >> n;
    g.resize(n);
    REP(i, n - 1){
        ll x, y;
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    cout << (dfs(0, -1)? "Alice" : "Bob") << endl;
}