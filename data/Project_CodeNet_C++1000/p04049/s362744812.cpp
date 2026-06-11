#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 1000000000

int N, K;
vector <int> adjList[2005];
int minAns = INF;

int p[2005];
void root(int u, int prevP)
{
    p[u] = prevP;
    for (int v : adjList[u])
    {
        if (prevP == v) continue;
        root(v, u);
    }
}

int getMinEven(int u, int p, int dist)
{
    int cur = 0;
    if (dist > K / 2) cur++;
    for (int v : adjList[u])
    {
        if (v == p) continue;
        cur += getMinEven(v, u, dist + 1);
    }
    return cur;
}

int getMinOdd(int source)
{
    if (source == 1) return INF;
    queue <int> bfs;
    int dist[2005];
    for (int i = 1; i <= N; i++) dist[i] = INF;
    dist[source] = 0, dist[p[source]] = 0;
    bfs.push(source); bfs.push(p[source]);
    int cur = 0;
    while (!bfs.empty())
    {
        int u = bfs.front(); bfs.pop();
        for (int v : adjList[u])
        {
            if (dist[v] > dist[u] + 1)
            {
                dist[v] = dist[u] + 1;
                bfs.push(v);
                if (dist[v] > K / 2) cur++;
            }
        }
    }
    return cur;
}

int main()
{
    scanf("%d%d", &N, &K);
    for (int i = 1; i < N; i++)
    {
        int A, B; scanf("%d%d", &A, &B);
        adjList[A].push_back(B); adjList[B].push_back(A);
    }
    root(1, -1);
    for (int i = 1; i <= N; i++)
    {
        if (K % 2 == 0) minAns = min(minAns, getMinEven(i, -1, 0));
        else minAns = min(minAns, getMinOdd(i));
    }
    printf("%d\n", minAns);
}
