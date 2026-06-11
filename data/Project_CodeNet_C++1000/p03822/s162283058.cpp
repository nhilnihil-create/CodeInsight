#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int N;
vector <int> wins[100005];

int dfs(int u)
{
    vector <int> depths;
    for (int v : wins[u])
    {
        depths.push_back(dfs(v));
    }
    sort(depths.begin(), depths.end(), greater<int>());
    int maxDepth = 0;
    for (int i = 0; i < depths.size(); i++)
    {
        int depth = depths[i];
        maxDepth = max(depth + i + 1, maxDepth);
    }
    return maxDepth;
}

int main()
{
    scanf("%d", &N);
    for (int i = 2; i <= N; i++)
    {
        int a; scanf("%d", &a);
        wins[a].push_back(i);
    }
    printf("%d\n", dfs(1));
}
