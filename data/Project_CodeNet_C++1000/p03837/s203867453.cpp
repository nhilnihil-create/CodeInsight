#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1e6 + 1;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> a(M), b(M), c(M);
    for (int i = 0; i < M; i++)
    {
        cin >> a.at(i) >> b.at(i) >> c.at(i);
    }

    vector<vector<int>> dist(N, vector<int>(N, INF));
    vector<vector<bool>> used(N, vector<bool>(N));
    for (int i = 0; i < M; i++)
    {
        int u = a.at(i) - 1, v = b.at(i) - 1;
        dist.at(u).at(v) = c.at(i);
        dist.at(v).at(u) = c.at(i);
        used.at(u).at(v) = true;
        used.at(v).at(u) = true;
    }

    int res = 0;
    for (int k = 0; k < N; k++)
    {
        for (int u = 0; u < N; u++)
        {
            for (int v = 0; v < N; v++)
            {
                if (dist.at(u).at(k) + dist.at(k).at(v) < dist.at(u).at(v))
                {
                    dist.at(u).at(v) = dist.at(u).at(k) + dist.at(k).at(v);
                    if (used.at(u).at(v))
                    {
                        res++;
                        used.at(u).at(v) = false;
                        used.at(v).at(u) = false;
                    }
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}
