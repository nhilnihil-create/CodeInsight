#include <bits/stdc++.h>
typedef long long ll;
std::vector <int> vec[100005];
int ans1[100005],ans2[100005];
int vis[100005];
int cnt1,cnt2;
void bfs(int begin, int ans[])
{
    std::queue <int> q;
    ans[begin] = 0;
    vis[begin] = 1;
    for (int i = 0; i < vec[begin].size(); i++)
    {
        q.push(vec[begin][i]);
        ans[vec[begin][i]] = 1;
        vis[vec[begin][i]] = 1;
    }
    while (!q.empty())
    {
        int z = q.front();
        int tmp = ans[z];
        q.pop();
        vis[z] = 1;
        for (int i = 0; i < vec[z].size(); i++)
        {
            if (vis[vec[z][i]])
                continue;
            vis[vec[z][i]] = 1;
            q.push(vec[z][i]);
            ans[vec[z][i]] = tmp + 1;
        }
    }
}
int main()
{
//    freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        int a,b;
        scanf("%d%d", &a, &b);
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    bfs(1, ans1);
    memset(vis, 0, sizeof(vis));
    bfs(n, ans2);
    for (int i = 1; i <= n; i++)
    {
        if (ans1[i] <= ans2[i])
            cnt1++;
        else
            cnt2++;
    }
    if (cnt1 > cnt2)
        printf("Fennec\n");
    else
        printf("Snuke\n");
    return 0;
}