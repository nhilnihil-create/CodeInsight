#include <bits/stdc++.h>

using ll = long long int;
using P = std::pair<int, ll>;

constexpr ll INF = -1e15;

#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{

    int n, m;

    std::cin >> n >> m;

    std::vector<std::vector<P>> g(n + 1);
    std::vector<std::vector<int>> rg(n + 1);

    rep(i, m)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        g[a].emplace_back(b, c);
        rg[b].emplace_back(a);
    }

    std::vector<ll> d(n + 1, INF);

    std::stack<int> stk;
    stk.push(n);

    std::set<int> set;

    set.emplace(n);

    while (!stk.empty())
    {
        int x = stk.top();

        stk.pop();

        for (auto y : rg[x])
        {
            if (!set.count(y))
            {
                stk.push(y);
                set.emplace(y);
            }
        }
    }

    d[1] = 0;

    rep(i, n)
    {
        bool f = 0;
        int pos = n;
        rep(j, n)
        {
            for (auto p : g[j + 1])
            {
                if (d[j + 1] != INF && p.second + d[j + 1] > d[p.first])
                {
                    if (d[p.first] != INF)
                    {
                        pos = p.first;
                    }
                    d[p.first] = d[j + 1] + p.second;
                    f = 1;
                }
            }
        }
        if (i == n - 1 && f && set.count(pos))
        {
            std::cout << "inf" << std::endl;
            return 0;
        }
    }

    std::cout << d[n] << std::endl;

    return 0;
}