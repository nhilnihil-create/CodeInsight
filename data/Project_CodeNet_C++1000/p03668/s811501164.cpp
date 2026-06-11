#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100005];

int getgrundy(int t, int p)
{
    int ret = 0;
    for (int nxt : graph[t])
    {
        if (nxt == p) continue;
        ret ^= getgrundy(nxt, t) + 1;
    }
    return ret;
}

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        scanf("%d%d",&a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    if (getgrundy(1, -1)) printf("Alice\n");
    else printf("Bob\n");
}
