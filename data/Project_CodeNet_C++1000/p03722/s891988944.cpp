#include <bits/stdc++.h>
using namespace std;

bool bellman_ford(const int v, const int s,
                  const vector<pair<pair<int, int>, int64_t>>& g,
                  vector<int64_t>& cost,
                  vector<bool>& negative)
{
    const int64_t inf = 1LL << 60;
    cost[s] = 0;
    for (auto i = 0; i < v * 2; i++) {
        for (auto & elm : g) {
            if(cost[elm.first.first] == inf) continue;
            if(cost[elm.first.second] > cost[elm.first.first] + elm.second) {
                if(i == v - 1) negative[elm.first.second] = true;
                cost[elm.first.second] = cost[elm.first.first] + elm.second;
            }
            // 閉路から進んだ先は閉路を含む扱いにする
            if(i >= v) if(negative[elm.first.first] == true) negative[elm.first.second] = true;
        }
    }
    return false;
}

int main(){
    int n, m; cin >> n >> m;
    vector<pair<pair<int, int>, int64_t>> g;
    const int64_t inf = 1LL << 60;
    vector<int64_t> cost(n, inf); vector<bool> negative(n, false);
    for (auto i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c; a--; b--;
        g.emplace_back(make_pair(a, b), -c);
    }
    bellman_ford(n, 0, g, cost, negative);
    if(negative[n - 1]) {
        cout << "inf" << endl;
        return 0;
    }
    cout << -cost[n - 1] << endl;
    return 0;
}