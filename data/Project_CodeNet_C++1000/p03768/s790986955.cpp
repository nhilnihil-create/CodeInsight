#include "bits/stdc++.h"
using namespace std;
const int maxn = 1e5 + 100;
typedef long long ll;
vector<int> e[maxn];
int n, m;
int ans[maxn];
int v[maxn], d[maxn], c[maxn];
int maxx[maxn];

struct node
{
    int vec, d;
};
queue<node> q;

void bfs(int v, int d, int c)
{
    node temp;
    temp.vec = v;
    temp.d = 0;
    if(maxx[v]<d-temp.d)
    {
        maxx[v]=d-temp.d;
        if(ans[temp.vec]==0)
        {
            ans[temp.vec]=c;
        }
        q.push(temp);
    }
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        int to = e[temp.vec].size();
        for (int i = 0; i < to; i++)
        {
            if(maxx[e[temp.vec][i]]<d-temp.d-1)
            {
                node te;
                te.vec=e[temp.vec][i];
                te.d=temp.d+1;
                maxx[te.vec]=d-te.d;
                if(ans[te.vec]==0)
                {
                    ans[te.vec]=c;
                }
                q.push(te);
            }

        }
    }
}
void init()
{
    for(int i=0; i<=n; i++)
    {
        maxx[i]=-1;
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    init();
    int a, b;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    int _;
    scanf("%d", &_);
    for (int i = 0; i < _; i++)
    {
        scanf("%d %d %d", &v[i], &d[i], &c[i]);
    }
    for (int i = _ - 1; i >= 0; i--)
    {
        bfs(v[i], d[i], c[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d\n", ans[i]);
    }
    return 0;
}
