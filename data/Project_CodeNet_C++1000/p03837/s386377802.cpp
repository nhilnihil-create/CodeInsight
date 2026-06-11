#include <iostream>
#include <vector>
#include <tuple>

using vec = std::vector<int>;
using Graph = std::vector<vec>;
using edge = std::tuple<int, int, int>;

Graph calc_minimum_dists(Graph g)
{
    Graph min_dist = g;
    int N = g.size();
    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                min_dist[i][j] =
                    std::min(min_dist[i][j], min_dist[i][k] + min_dist[k][j]);

    return min_dist;
}

int calc_unuse_edge_count(
    Graph &d, std::vector<edge> &es
)
{
    int N = d.size();
    int unuse_edge_count = 0;
    for (auto e : es) {
        int a = std::get<0>(e);
        int b = std::get<1>(e);
        int c = std::get<2>(e);

        if (d[a][b] != c)
            unuse_edge_count += 1;
    }
    return unuse_edge_count;
}

int main()
{
    int N, M;
    std::cin >> N >> M;
    Graph d(N, vec(N, 1e9));
    std::vector<edge> e;

    for (int i = 0; i < N; i++)
        d[i][i] = 0;

    for (int i = 0; i < M; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        a--; b--;
        d[a][b] = d[b][a] = c;
        e.emplace_back(a, b, c);
    }

    Graph min_dist = calc_minimum_dists(d);
    std::cout << calc_unuse_edge_count(min_dist, e) << std::endl;
    return 0;
}