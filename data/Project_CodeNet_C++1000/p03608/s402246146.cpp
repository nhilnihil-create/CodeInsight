#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using Vertex = std::uint32_t;
using Weight = std::uint32_t;
using Graph = std::vector<std::vector<std::pair<Vertex, Weight>>>;

const auto Inf = std::numeric_limits<Weight>::max();
std::vector<Weight> Dijkstra(const Vertex s, const Graph& g)
{
    auto n = g.size();
    auto dist = std::vector<Weight>(n, Inf);
    dist[s] = 0;

    auto comp = [](auto x, auto y) { return x.second > y.second; };
    auto q =
        std::priority_queue<std::pair<Vertex, Weight>, std::vector<std::pair<Vertex, Weight>>, decltype(comp)>(comp);

    auto visited = std::vector<bool>(n, false);
    q.emplace(s, dist[s]);
    while (!q.empty())
    {
        auto v = q.top().first;
        q.pop();

        if (visited[v]) continue;

        visited[v] = true;

        for (const auto& node : g[v])
        {
            auto v_n = node.first;
            auto d_n = node.second;

            if (dist[v_n] > dist[v] + d_n)
            {
                dist[v_n] = dist[v] + d_n;
                q.emplace(v_n, dist[v_n]);
            }
        }
    }
    return dist;
}
int main()
{
    auto n = Vertex();
    auto m = Vertex();
    auto r = Weight();

    std::cin >> n >> m >> r;

    auto c = std::vector<Vertex>(r);
    for (Vertex i = 0; i < r; ++i)
    {
        std::cin >> c[i];
        --c[i];
    }
    std::sort(c.begin(), c.end());

    auto g = Graph(n);
    for (Vertex i = 0; i < m; ++i)
    {
        Vertex a;
        Vertex b;
        Vertex w;

        std::cin >> a >> b >> w;

        g[a - 1].emplace_back(b - 1, w);
        g[b - 1].emplace_back(a - 1, w);
    }

    auto dist_list = std::vector<std::vector<Weight>>();
    dist_list.reserve(r);
    for (Vertex s = 0; s < n; ++s)
    {
        dist_list.emplace_back(Dijkstra(s, g));
    }

    auto result = Weight(Inf);
    do
    {
        auto distance = Weight(0);
        for (Vertex i = 0; i < r - 1; ++i) distance += dist_list[c[i]][c[i + 1]];

        if (distance < result) result = distance;

    } while (std::next_permutation(c.begin(), c.end()));

    std::cout << result << std::endl;

    return 0;
}