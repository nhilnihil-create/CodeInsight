#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, a, b, q;
    cin >> n >> m;
    vector <int> D[n+1], T;
    int Di[n+1], C[n+1];
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        D[a].push_back(b);
        D[b].push_back(a);
    }
    for (int i = 0; i <= n; i++)
    {
        C[i] = 0;
        Di[i] = -1;
    }
    cin >> q;
    int v[q], d[q], c[q];
    for (int i = 0; i <= n; i++)
    {
        Di[i] = -1;
    }
    for (int i = 0; i < q; i++)
    {
        cin >> v[i] >> d[i] >> c[i];
    }
    for (int i = q-1; i >= 0; i--)
    {
        if (d[i] > Di[v[i]])
        {
            Di[v[i]] = d[i];
            T.push_back(v[i]);
            for (int y = 0; y < T.size(); y++)
            {
                a = T[y];
                if (C[a] == 0)
                {
                    C[a] = c[i];
                }
                for (int u = 0; u < D[a].size(); u++)
                {
                    b = D[a][u];
                    if (Di[b] < Di[a]-1)
                    {
                        Di[b] = Di[a]-1;
                        T.push_back(b);
                    }
                }
            }
            T.clear();
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << C[i] << "\n";
    }
    return 0;
}
