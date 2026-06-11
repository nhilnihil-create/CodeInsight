/**
 *   @FileName	a.cpp
 *   @Author	kanpurin
 *   @Created	2020.08.12 03:24:22
**/

#include "bits/stdc++.h" 
using namespace std; 
typedef long long ll;



struct BellmanFord {
private:
    struct edge {
        int to;
        long long cost;
        edge(int to, long long cost) : to(to), cost(cost) {}
    };
    int N;
    std::vector< std::vector< edge > > G;
public:
    std::vector<long long> d;
    long long inf = 1e18 + 1;
    BellmanFord(int n) {
        N = n;
        G.resize(N);
    }
    void add_edge(int from, int to, long long cost, bool directed = false) {
        G[from].push_back(edge(to, cost));
        if (!directed) G[to].push_back(edge(from, cost));
    }
    void build(int s) {
        d = std::vector< long long >(N, inf);
        d[s] = 0;
        bool update = true;
        int i = 0;
        while (update) {
            update = false;
            for (int j = 0; j < N; j++) {
                for (const edge& e : G[j]) {
                    if (d[j] != -inf && d[j] != inf && d[j] + e.cost < d[e.to]) {
                        d[e.to] = d[j] + e.cost;
                        if (i == N - 1) {
                            d[e.to] = -inf;
                        }
                        update = true;
                    } else if (d[j] == -inf && d[e.to] != -inf) {
                        d[e.to] = -inf;
                        update = true;
                    }
                }
            }
            if (i < N - 1) i++;
        }
    }
};
int main() {
    int n, m;
    cin >> n >> m;
    BellmanFord bf(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        bf.add_edge(a,b,-c,true);
    }
    bf.build(0);
    if (bf.d[n - 1] == -bf.inf) {
        puts("inf");
    } else {
        cout << -bf.d[n - 1] << endl;
    }
    return 0;
}
