#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M; cin >> N >> M;

    auto adjacency_list = vector<vector<int>>(N);
    for (auto i = 0; i < M; i++)
    {
        int a, b; cin >> a >> b;
        a--; b--;
        adjacency_list[a].push_back(b);
        adjacency_list[b].push_back(a);
    }

    auto seen = vector<bool>(N);
    auto colors = vector<bool>(N);
    const function<bool(int, bool)> dfs = [&](const int v, const bool color)
    {
        if (seen[v]) return colors[v] == color;
        else
        {
            seen[v] = true;
            colors[v] = color;
        }

        auto is_bipartite = true;
        for (const auto w : adjacency_list[v])
            is_bipartite &= dfs(w, !color);
        return is_bipartite;
    };

    auto singletons = 0LL, bipartites = 0LL, nonbipartites = 0LL;
    for (auto v = 0; v < N; v++) if (!seen[v])
    {
        if (adjacency_list[v].size() == 0) singletons++;
        else if (dfs(v, true)) bipartites++;
        else nonbipartites++;
    }

    auto answer = 0LL;
    answer += 2*singletons*N - singletons*singletons;
    answer += (bipartites + nonbipartites) * (bipartites + nonbipartites);
    answer += bipartites * bipartites;
    cout << answer << endl;
}
