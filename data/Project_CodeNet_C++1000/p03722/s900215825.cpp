#include <iostream>
#include <limits>
#include <vector>
using namespace std;

struct edge {
    int to;
    int from;
    int64_t point;
};

#define INF -(int64_t)(1e18)

int main() {
    int N, M;
    cin >> N >> M;

    vector<edge> E(M);
    vector<int64_t> P(N, INF);

    for (int i = 0; i < M; ++i) {
        cin >> E[i].from >> E[i].to >> E[i].point;
        E[i].from--;
        E[i].to--;
    }

    P[0] = 0;

    int cnt = 0;
    int64_t ds;
    bool flag = false;
    bool update = true;

    while (update && cnt < 2 * N) {
        cnt++;
        bool update = false;

        for (const auto &e : E) {
            if (P[e.from] != INF && P[e.to] < P[e.from] + e.point) {
                P[e.to] = P[e.from] + e.point;
                update = true;
            }
        }

        if (cnt == N - 1) {
            ds = P[N - 1];
        }

        if (cnt == 2 * N && ds < P[N - 1]) {
            goto loop;
        }
    }
end:
    cout << P[N - 1] << endl;
    return 0;
loop:
    cout << "inf" << endl;
    return 0;
}