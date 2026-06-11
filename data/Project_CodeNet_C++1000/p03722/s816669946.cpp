#include <iostream>
#include <vector>

using int64 = long long;
constexpr static int64 INF = 1e15;

struct Edge {
    int from;
    int to;
    int64 cost;

    Edge(int from, int to, int64 cost)
        : from{from}, to{to}, cost{cost} {}
};

class BellmanFord {
private:
    int V;
    int E;
    std::vector<Edge> es;
    std::vector<int64> d;

public:
    BellmanFord(int V, int E, std::vector<Edge> es)
        : V{V}, E{E}, es{es} {}

    bool find_negative_loop(int s)
    {
        d.assign(V, INF);
        d[s] = 0;

        int cnt = 0;
        bool update = false;
        for (int i = 0; i < V; i++) {
            update = false;
            cnt++;
            for (const Edge &e : es) {
                if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
                    d[e.to] = d[e.from] + e.cost;
                    if (cnt == V && e.to == V - 1)
                        return true;

                    update = true;
                }
            }

            if (!update)
                break;
        }

        return false;
    }

    std::vector<int64> calc_shortest_path(int s) {
        if (find_negative_loop(s))
            return {};

        return d;
    }
};

int main()
{
    int N, M;
    std::cin >> N >> M;

    std::vector<Edge> es;
    for (int i = 0; i < M; i++) {
        int a, b;
        int64 c;
        std::cin >> a >> b >> c;
        a--; b--;
        es.emplace_back(a, b, -c);
    }

    BellmanFord bf{N, M, es};
    auto d = bf.calc_shortest_path(0);
    if (d.empty())
        std::cout << "inf" << std::endl;
    else
        std::cout << -d[N - 1] << std::endl;

    return 0;
}