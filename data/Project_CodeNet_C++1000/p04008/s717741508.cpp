#include <cstdio>
#include <vector>
#include <utility>
#include <tuple>
#include <algorithm>
#include <functional>

using namespace std;

typedef pair <int, int> ii;

int N, K;
vector <int> adjList[100005];
int kp[100005];
vector <ii> sortedDist;
bool fixed[100005];
int ans;

int p[20][100005], dist[100005];
void root(int u, int prevP, int prevDist)
{
    p[0][u] = prevP, dist[u] = prevDist;
    for (int v : adjList[u])
    {
        if (v == prevP) continue;
        root(v, u, prevDist + 1);
    }
}

void markFixed(int u)
{
    fixed[u] = true;
    for (int v : adjList[u])
    {
        if (v == p[0][u]) continue;
        if (!fixed[v]) markFixed(v);
    }
}

int main()
{
    scanf("%d%d", &N, &K);
    for (int i = 1; i <= N; i++)
    {
        int a; scanf("%d", &a);
        if (i == 1 && a != 1) ans++;
        else adjList[i].push_back(a), adjList[a].push_back(i);
    }
    root(1, -1, 0);
    for (int k = 1; k < 20; k++) for (int i = 1; i <= N; i++)
    {
        if (p[k-1][i] == -1) p[k][i] = -1;
        else p[k][i] = p[k-1][p[k-1][i]];
    }
    for (int i = 1; i <= N; i++)
    {
        kp[i] = i;
        int temp = K - 1;
        for (int k = 19; k >= 0; k--)
        {
            if (temp >= (1 << k))
            {
                if (kp[i] != -1) kp[i] = p[k][kp[i]];
                temp -= (1 << k);
            }
        }
    }
    for (int i = 1; i <= N; i++)
    {
        sortedDist.emplace_back(dist[i], i);
    }
    sort(sortedDist.begin(), sortedDist.end(), greater <ii>());
    for (ii temp : sortedDist)
    {
        int d, u; tie(d, u) = temp;
        if (fixed[u]) continue;
        else
        {
            int parent = kp[u];
            if (parent != -1)
            {
                markFixed(parent);
                if (p[0][parent] != 1 && parent != 1) ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
