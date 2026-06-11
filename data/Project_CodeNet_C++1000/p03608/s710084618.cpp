#include <iostream>
#include <vector>

static const long long INF = (1LL<<60);

int main() {
    int N, M, R; std::cin >> N >> M >> R;
    std::vector<int> r(R);
    for (int i = 0; i < R; i++) {
        std::cin >> r[i];
        r[i]--;  // 0 begin;
    }
    std::vector<std::vector<long long >> G(N, std::vector<long long>(N, INF));
    for (int i = 0; i < N; i++) {
        G[i][i] = 0;
    }

    for (int i = 0; i < M; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        a--; b--;
        G[a][b] = G[b][a] = c;
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                G[i][j] = std::min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }

    std::sort(r.begin(), r.end());
    long long min = INF;
    do {
        long long s = 0;
        for (int i = 1; i < R; i++) {
            s += G[r[i-1]][r[i]];
        }
        min = std::min(min, s);
    } while (std::next_permutation(r.begin(), r.end()));

    std::cout << min << std::endl;
    return 0;
}