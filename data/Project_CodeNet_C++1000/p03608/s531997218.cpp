#include <iostream>
#include <vector>

static void rec(int bit, int prev, int sum, int R, const std::vector<int>& r,
    const std::vector<std::vector<int>>& G,
    const std::vector<std::vector<int>>& memo,
    int& min)
{
    if (bit == ((1 << R) - 1)) {
        if (min == -1) {
            min = sum;
        } else {
            min = std::min(min, sum);
        }
    }

/*
    if (prev != -1 && memo[prev][bit] != -1) {
        if (min == -1) {
            min = sum + memo[prev][bit];
        } else {
            min = std::min(min, sum + memo[prev][bit]);
        }
    }
    */

    for (int i = 0; i < R; i++) {
        if (((bit >> i) & 0x01) == 1) {
            continue;
        }
        int s = sum;
        if (prev != -1) {
            s += G[r[prev]][r[i]];
        }
        rec(bit | (1 << i), i, s, R, r, G, memo, min);
    }
}

int main() {
    int N, M, R; std::cin >> N >> M >> R;
    std::vector<int> r(R);
    for (int i = 0; i < R; i++) {
        std::cin >> r[i];
        r[i]--;  // 0 begin;
    }
    std::vector<std::vector<int>> G(N, std::vector<int>(N, -1));
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
                if (G[i][k] == -1 || G[k][j] == -1) {
                    continue;
                }

                if (G[i][j] == -1) {
                    G[i][j] = G[i][k] + G[k][j];
                }

                G[i][j] = std::min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }

    std::vector<std::vector<int>> memo(N, std::vector<int>(256, -1));
    int min = -1;
    rec(0, -1, 0, R, r, G, memo, min);
    std::cout << min << std::endl;
    return 0;
}
