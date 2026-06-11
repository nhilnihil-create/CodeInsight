#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const long long INF = 1LL<<60;
const int MAX = 210;

int N, M, R;
long long dist[MAX][MAX];

int main() {
    cin >> N >> M >> R;
    vector<int> vr;
    for (int i = 0; i < R; ++i) {  int r; cin >> r; --r; vr.push_back(r); }
    
    // Floyd-Warshall の初期化: dist[i][i] = 0 に注意
    for (int i = 0; i < 210; ++i) {
        for (int j = 0; j < 210; ++j) dist[i][j] = INF;
        dist[i][i] = 0;
    }
    
    // 入力と Floyd-Warshall
    for (int i = 0; i < M; ++i) {
        int a, b, c; cin >> a >> b >> c; --a, --b;
        dist[a][b] = c;
        dist[b][a] = c;
    }
    for (int k = 0; k < N; ++k)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    // R! 通りの探索
    long long res = INF;
    sort(vr.begin(), vr.end());
    do {
        long long tmp = 0;
        for (int i = 1; i < vr.size(); ++i) tmp += dist[vr[i]][vr[i-1]];
        res = min(res, tmp);
    } while (next_permutation(vr.begin(), vr.end()));

    cout << res << endl;
}