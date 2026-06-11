#include <iostream>
using namespace std;
const int INF = 1<<29;
const int MAX_V = 110;
const int MAX_E = 1100;

int N, M;
int a[MAX_E], b[MAX_E], c[MAX_E];
int dist[MAX_V][MAX_V]; 

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            dist[i][j] = INF;
        }
        dist[i][i] = 0;
    }

    for (int i = 0; i < M; ++i) {
        cin >> a[i] >> b[i] >> c[i];
        --a[i], --b[i];
        dist[a[i]][b[i]] = c[i];
        dist[b[i]][a[i]] = c[i];
    }

    for (int k = 0; k < N; ++k)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    int res = 0;
    for (int i = 0; i < M; ++i) {
        if (c[i] > dist[a[i]][b[i]]) ++res;
    }
    cout << res << endl;
}