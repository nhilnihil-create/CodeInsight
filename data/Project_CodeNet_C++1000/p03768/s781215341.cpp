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
#include <cstdlib>
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

#define REP(i, n) for(int i = 0; i < (int)n; i++)




vector<vector<int>> g;
vector<int> range, ans;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<int>> g(n);
    vector<int> range(n, -1), ans(n);
    REP(i, m){
        int a, b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int q;
    cin >> q;
    vector<int> v(q), d(q), c(q);
    REP(i, q){
        scanf("%d %d %d", &v[i], &d[i], &c[i]);
        v[i]--;
    }
    for(int i = q - 1; i >= 0; i--){
        queue<pair<int, int>> q;
        vector<bool> used(n, false);
        if(range[v[i]] < d[i]){
            q.push({v[i], d[i]});
        }
        while(!q.empty()){
            auto t = q.front(); q.pop();
            if(used[t.first]) continue;
            if(!ans[t.first]) ans[t.first] = c[i];
            used[v[i]] = true;
            range[t.first] = t.second;
            if(t.second){
                for(auto &x : g[t.first]){
                    if(!used[x] && range[x] + 1 < t.second){
                        q.push({x, t.second - 1});
                    }
                }
            }
        }
    }
    REP(i, n){
        printf("%d\n", ans[i]);
    }
}