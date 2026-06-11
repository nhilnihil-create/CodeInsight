#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <fstream>
#include <cmath>
#include <random>
#include <complex>
#include <functional>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)
using namespace std;
typedef vector<ll> vec;
typedef vector<vec> mat;

const ll inf = 1LL << 60;

template<class T> inline void chmin(T& a, T b) {
    if (a > b) {
        a = b;
    }
}
template<class T> inline void chmax(T& a, T b) {
    if (a < b) {
        a = b;
    }
}

typedef pair<ll, ll> P;
vec d;
struct edge {
    ll to, cost;
};
vector<vector<edge>> G;

void dijkstra (ll s, ll V) {
    priority_queue<P, vector<P>, greater<P>> que;
    d.assign(V, inf);
    d[s] = 0;
    que.push(P(0, s));

    while (!que.empty()) {
        P p = que.top(); que.pop();
        ll v = p.second;
        if (d[v] < p.first) continue;
        for (edge e : G[v]) {
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, M;
    cin >> N >> M;
    G.assign(N, vector<edge>());
    while (M--) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back({b, 1});
        G[b].push_back({a, 1});
    }

    set<ll> path;
    deque<ll> order;
    ll start = 0;
    ll finish = G[0][0].to;
    // cout << start << " " << finish << "\n";
    path.insert(0);
    path.insert(G[0][0].to);
    order.push_front(start);
    order.push_back(finish);

    while (true) {
        bool flag = false;
        for (auto e : G[start]) {
            if (path.find(e.to) == path.end()) {
                path.insert(e.to);
                order.push_front(e.to);
                start = e.to;
                flag = true;
                break;
            }
        }

        if (flag) continue;

        for (auto e : G[finish]) {
            if (path.find(e.to) == path.end()) {
                path.insert(e.to);
                order.push_back(e.to);
                finish = e.to;
                flag = true;
                break;
            }
        }

        if (!flag) break;
    }

    cout << order.size() << "\n";

    for (ll e : order) {
        cout << e+1 << " ";
    }

    cout << "\n";

}