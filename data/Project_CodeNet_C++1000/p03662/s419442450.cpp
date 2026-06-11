#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
vector<int> adjList[MAXN + 1];
int s[MAXN + 1];
vector<int> path;

void dfs(int v, int parent, vector<int>& recurse, int n)
{
    recurse.push_back(v);
    if (v == n)
        path = recurse;
    s[v] = 1;
    for (int adj : adjList[v])
    {
        if (adj != parent)
        {
            dfs(adj, v, recurse, n);
            s[v] += s[adj];
        }
    }
    recurse.pop_back();
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    vector<int> temp;
    dfs(1, 0, temp, n);
    int meet = path[(int) (path.size() - 1) / 2 + 1];
    int s2 = s[meet];
    int s1 = n - s2;
    cout << (s1 > s2 ? "Fennec" : "Snuke") << endl;
    return 0;
}
