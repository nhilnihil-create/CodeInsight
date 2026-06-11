#include <iostream>
#include <iomanip>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <map>
#include <unordered_map>
#include <set>
#include <climits>
#include <bitset>

#define ll long long
const ll MOD = 1e9 + 7;

// 隣接リストで使う辺を表す型
struct BellmanfordEdge
{
    ll to;
    ll cost;
    BellmanfordEdge(ll to, ll cost) :to(to), cost(cost) {}
};

// 戻り値が空配列なら負の閉路を含む
std::vector<ll> Bellmanford(ll s, std::vector<std::vector<BellmanfordEdge>>& connection)
{
    // 2 <= N <= 1000, -10^9 <= cost
    const ll INF = 1000000000001;
    auto n = connection.size();
    auto dist = std::vector<ll>(n, -INF);

    dist[s] = 0;

    std::vector<bool> containsCircuit(n, false);
    for (auto i=0; i<n; i++)
    {
        for (auto v=0; v<n; v++)
        {
            if (dist[v] == -INF)
                continue;

            for (auto k = 0; k < connection[v].size(); k++)
            {
                auto edge = connection[v][k];
                if (dist[edge.to] < dist[v] + edge.cost)
                {
                    dist[edge.to] = dist[v] + edge.cost;

                    // Bellmanford ではグラフの走査回数ごとに始点からN次の点までの最小距離しか考慮できない.
                    // 故に N - 1 回更新すれば各点への最小距離が求まる.
                    // それでも最小距離更新の余地があるなら負の閉路が存在する
                    if (i == n - 1)
                        containsCircuit[v] = true;
                }
            }
        }
    }

    // 閉路がゴール(n番目の頂点)までの経路にあるか
    for (auto v=0; v<n; v++)
    {
        if (!containsCircuit[v])
            continue;

        for (auto k = 0; k < connection[v].size(); k++)
        {
            if (containsCircuit[v])
                containsCircuit[connection[v][k].to] = true;
        }
    }

    return containsCircuit[n - 1] ? std::vector<ll>() : dist;
}

int main()
{
    ll N, M;
    std::cin >> N >> M;
    std::vector<std::vector<BellmanfordEdge>> connection(N, std::vector<BellmanfordEdge>());

    for (auto i=0; i<M; ++i)
    {
        ll from, to, cost;
        std::cin >> from >> to >> cost;
        from--;
        to--;
        connection[from].emplace_back(BellmanfordEdge(to, cost));
    }

    auto result = Bellmanford(0, connection);
    if (result.empty())
        std::cout << "inf" << std::endl;
    else
        std::cout << result[N-1] << std::endl;
}
