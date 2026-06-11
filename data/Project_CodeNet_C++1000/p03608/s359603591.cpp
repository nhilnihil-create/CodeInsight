#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N, M, R;
    std::cin >> N >> M >> R;
    std::vector<int> r(R);
    for (int i = 0; i < R; i++) {
        std::cin >> r[i];
        r[i]--;
    }

    std::sort(r.begin(), r.end());

    constexpr int INF = 1e9;
    std::vector<std::vector<int>> d(N, std::vector<int>(N, INF));
    for (int i = 0; i < N; i++)
        d[i][i] = 0;

    for (int i = 0; i < M; i++) {
        int A, B, C;
        std::cin >> A >> B >> C;
        A--; B--;
        d[A][B] = d[B][A] = C;
    }

    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);

    int min_dist = INF;
    do {
        int dist = 0;
        for (int i = 1; i < (int)r.size(); i++)
            dist += d[r[i - 1]][r[i]];

        min_dist = std::min(min_dist, dist);
    } while (std::next_permutation(r.begin(), r.end()));

    std::cout << min_dist << std::endl;
    return 0;
}