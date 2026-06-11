#include <iostream>
#include <vector>
using namespace std;
int N;
vector <pair <int, int> > G[200005];
int root, Cost[200005], A[200005];
bool ok = 1;
void Read()
{
    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> A[i];
    for(int i = 1; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        G[x].push_back(make_pair(y, i));
        G[y].push_back(make_pair(x, i));
        //E[i] = make_pair(x, y);
    }
}
void precalcRoot()
{
    for(int i = 1; i <= N; i++)
    {
        if(G[i].size() >= 2)
        {
            root = i;
            break;
        }
    }
}
void DFS(int node, int father, int e)
{
    int val = A[node];
    if(G[node].size() > 1)
    {
        val *= 2;
    }
    for(int i = 0; i < G[node].size(); i++)
    {
        int neighb = G[node][i].first, edge = G[node][i].second;
        if(neighb == father)
            continue;
        DFS(neighb, node, edge);
        val -= Cost[edge];
    }
    Cost[e] = val;
    if(Cost[e] < 0)
    {
        ok = 0;
        return;
    }
}
void Solve()
{
    DFS(root, 0, 0);
    if(ok == 0)
        return;
    if(Cost[0] != 0)
    {
        ok = 0;
        return;
    }
    for(int i = 1; i <= N; i++)
    {
        if(G[i].size() == 1)
            continue;
        int sum = 0;
        for(int j = 0; j < G[i].size(); j++)
        {
            int neighb = G[i][j].first, edge = G[i][j].second;
            sum += Cost[edge];
        }
        if(sum % 2 == 1)
        {
            ok = 0;
            return;
        }
        for(int j = 0; j < G[i].size(); j++)
        {
            int neighb = G[i][j].first, edge = G[i][j].second;
            if(sum / 2 < Cost[edge])
            {
                ok = 0;
                return;
            }
        }
    }
}
int main()
{
    Read();
    if(N == 2)
    {
        if(A[1] == A[2])
        {
            cout << "YES\n";
            return 0;
        }
        cout << "NO\n";
        return 0;
    }
    precalcRoot();
    Solve();
    if(ok == 0)
    {
        cout << "NO\n";

    }
    else
        cout << "YES\n";
    return 0;
}
