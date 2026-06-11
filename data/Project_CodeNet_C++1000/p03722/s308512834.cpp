#include <bits/stdc++.h>
using namespace std;

struct edge {
    int from;
    int to;
    long long cost;
};
long long INF = 1e12;

vector<long long> bellman_ford(vector<edge> es, int start_point, int vertex_num) {
    vector<long long> shortest_path(vertex_num, INF);
    shortest_path[start_point] = 0;
    for (int i = 0; i < vertex_num-1; i++) {
        for (int j = 0; j < es.size(); j++) {
            shortest_path[es[j].to] = min(shortest_path[es[j].to], shortest_path[es[j].from]+es[j].cost);
        }
    }
    return shortest_path;
}

bool find_negative_loop(vector<edge> es, int start_point, int vertex_num) {
    vector<long long> shortest_path(vertex_num, INF);
    shortest_path[start_point] = 0;
    for (int i = 0; i < vertex_num; i++) {
        for (int j = 0; j < es.size(); j++) {
            if (shortest_path[es[j].to] > shortest_path[es[j].from]+es[j].cost) {
                shortest_path[es[j].to] = shortest_path[es[j].from]+es[j].cost;
                if (i == vertex_num-1 && es[j].to == vertex_num-1)
                    return true;
            }
        }
    }
    return false;
}

int main(void){
    int N, M;
    cin >> N >> M;
    vector<edge> es(M);
    for (int i = 0; i < M; i++) {
        cin >> es[i].from >> es[i].to >> es[i].cost;
        es[i].from--;
        es[i].to--;
        es[i].cost = -es[i].cost;
    }
    if (find_negative_loop(es, 0, N))
        cout << "inf";
    else {
        vector<long long> shortest_path = bellman_ford(es, 0, N);
        cout << -shortest_path[N-1];
    }
}