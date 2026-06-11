#include <iostream>
#include <vector>
// #include <algorithm>
// #include <set>
// #include <string>
// #include <cmath>
// #include <map>
// #include <iomanip>

#define MOD 1000000007

using namespace std;
// typedef unsigned long long ull;
typedef long long ll;

void p() {
    cout << "\n";
}
template<class Head, class... Body>
void p(Head head, Body... body) {
    cout << head << ",";
    p(body...);
}

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[";
    for (const auto i : v) {
        os << i << " ";
    }
    os << "]";
    return os;
}

struct Edge {
    int from;
    int to;
    int cost;
};

int main(int argc, char const *argv[]) {
    int N, M;
    cin >> N >> M;

    vector<int> a(M);
    vector<Edge> E;
    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        E.push_back({a-1, b-1, -c});
    }

    vector<ll> dist(N, 0);
    vector<bool> visited(N, false);
    visited[0] = true;
    bool inf = false;
    for (int i = 0; i < N; ++i) {
        bool update = false;
        for (const auto& edge : E) {
            if (visited[edge.from] && (!visited[edge.to] || dist[edge.to] > dist[edge.from] + edge.cost)) {
                dist[edge.to] = dist[edge.from] + edge.cost;
                visited[edge.to] = true;
                update = true;
                if (i == N-1 && edge.to == N-1) {
                    inf = true;
                }
            }
        }
        // cout << i << " update:" << update << endl;
        // cout << visited << endl;
        // cout << dist << endl;
        if (!update) {
            break;
        }
    }

    if (inf) {
        cout << "inf" << endl;
    } else {
        cout << -dist[N-1] << endl;
    }

    return 0;
}
