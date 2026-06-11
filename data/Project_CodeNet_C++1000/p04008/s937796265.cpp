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





ll k, ans = 0;
vector<vector<ll>> g;

ll dfs(ll now, ll par){
    ll res = 0;
    for(auto &v : g[now]){
        res = max(res, dfs(v, now));
    }
    if(res >= k - 1 && par != 0){
        ans++;
        res = -1;
    }
    return res + 1;
}

int main() {
    ll n;
    cin >> n >> k;
    g.resize(n);
    REP(i, n){
        ll a;
        cin >> a;
        a--;
        if(i > 0){
            g[a].push_back(i);
        }
        else if(a != 0){
            ans++;
        }
    }
    dfs(0, 0);
    cout << ans << endl;
}
