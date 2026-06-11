#include <bits/stdc++.h>
using namespace std;
const int maxn = 300 + 5;
int n,m,ans = maxn;
int cnt[maxn];
int mapp[maxn][maxn];
int vis[maxn];
vector <int> vec[maxn];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            scanf("%d", &mapp[i][j]);
        vec[mapp[i][cnt[i]++]].emplace_back(i);
    }
    int flag = 1;
    while (flag)
    {
        int v = 0, ii = 0;
        for (int i = 1; i <= m; ++i)
            if (vec[i].size() > v)
            {
                v = vec[i].size();
                ii = i;
            }
        if (!v)
            break;
        ans = min(ans, v);
        for (int i = 0; i < v; ++i)
        {
            int p = vec[ii][i];
            while (cnt[p] < m && vis[mapp[p][cnt[p]]])
                ++cnt[p];
            if (cnt[p] > m)
            {
                flag = 0;
                break;
            }
            vec[mapp[p][cnt[p]++]].emplace_back(p);
        }
        vec[ii].clear();
        vis[ii] = 1;
    }
    printf("%d\n", ans);
    return 0;
}